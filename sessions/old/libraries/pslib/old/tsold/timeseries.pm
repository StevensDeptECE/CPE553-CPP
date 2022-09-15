#!/usr/bin/perl
use strict;
use POSIX;

my ($title, $creator, $author, $copyright);

my $version = 0.1;
my @libraries = ("timeseries.ps");
my ($sec, $min, $hour, $day, $month, $year, $weekday, $dayofyear,$isdst) = localtime(time);
my $creationDate = sprintf("%4d/%02d/%02d %02d:%02d:%02d",$year+1900,$month+1,$day, $hour, $min, $sec);
my $borderSize = 40; # default, change this if you want
my $pageSizeName = "Letter"; # default
my $orientation = "Portrait"; # or landscape
my %pageSizes = ("Letter", [612,792], "Legal", [612, 1008], "Tabloid", [792,1224]);
my $stackSize = 300000;
my ($pageSize, $boundBox);

# variables substituted in text of postscript file $xxx =>value
my %vars = ("graphite", "graphite5d postscript V0.11");
my $plotfile;
my $libraries = "";
foreach my $library (@libraries) {
  open(LIB, $library) || die "Failed to open file $library\n";
  my @librarycode = <LIB>;
  $libraries .= join("",@librarycode);
  close(LIB);
}

sub setPageSize {
   ($pageSizeName) = @_;
   my $psize = $pageSizes{$pageSizeName};
   $pageSize = $orientation eq "portrait" ? $psize : [$$psize[1], $$psize[0]];
   $boundBox = "$borderSize $borderSize ". 
       ($$pageSize[0]-$borderSize). " " . ($$pageSize[1]-$borderSize);
   $vars{"boundBox"} = $boundBox;
   $vars{"date"} = $creationDate;
}


sub header {
    ($pageSizeName, $orientation, $borderSize) = @_;
    setPageSize($pageSizeName);
    
print <<EOF
%!PS-Adobe-3.0
%%Title: $title
%%For:
%%Creator: Graphite$version
%%CreationDate: $creationDate
%%BoundingBox: $boundBox
%%DocumentData: Clean7Bit
%%Orientation: Landscape
%%Pages: 1
%%PageOrder: Ascend
%%DocumentMedia: $pageSizeName $$pageSize[0] $$pageSize[1] 0 () ()
%%DocumentNeededResources
%%DocumentProcessColors: Color
%%EndComments
%%BeginProlog
%%Copyright: $copyright
%%EndProlog
%%BeginSetup
%%EndSetup
EOF
;
}

sub pageprolog {
    my ($pagenum) = @_;
print<<EOF
%%Page: ($pagenum) $pagenum
%%BeginPageSetup
<< /PageSize [$$pageSize[0] $$pageSize[1]] >> setpagedevice
<< /MaxOpStack $stackSize >> setuserparams
%%EndPageSetup
$libraries
EOF
;
}


sub pagetrailer {
print <<EOF
showpage
EOF
;
}


sub trailer {
print <<EOF
%%Trailer
%%EOF
EOF
;
}

sub drawMap {
  my ($boundXmin, $boundYmin, $boundXmax, $boundYmax,
      $x1, $y1, $x2, $y2,
      $coast, $coaststyle, $m, $n, $grid, $gridstyle, $components) = @_;
print <<EOF
  gsave
  $boundXmin $boundYmin $boundXmax $boundYmax
  $x1 $y1 $x2 $y2 scaleRect
  $gridstyle
  $x1 $x2 $m $y1 $y2 $n drawgrid
  $coaststyle
  $coast drawcoastline
EOF
;
  if ($components) {
     eval $components;
  }
print <<EOF
grestore
grid 136 424 curvgrid pop
EOF
;
}

sub openbatch {
  my ($file) = @_;
  open (PLOTCTRL, $file) | die("Can't open $file $!");
  my $pagenum = 0;
  while (my $line = <PLOTCTRL>) {
    $line =~ s/\#.*$//g;
    if ($line =~ /^plot$/) {
      header();
      pageprolog($pagenum+1);
      open(PAGE, $plotfile) || die("can't open $plotfile  $!");
      while (my $line = <PAGE>) {
	$line =~ s/\$(\w+)/$vars{$1}/g;
	print $line;
	pagetrailer();
      }
      trailer();
    }
  }
  close(PLOTCTRL);
}

sub applyStyle {
  my ($style) = @_;
  return $style->{"linewidth"} . " setlinewidth " . $style->{"linecolor"} . " setrgbcolor " .
    $style->{"dashstyle"} . " setdash\n";
}

sub horizontalLine {
  my ($graph, $y, $style) = @_;
  $y = $y * $graph->{yScale} + $graph->{yOffset};
  $graph->{ps} .= applyStyle($style) .  "$graph->{x0pts} $y moveto $graph->{x1pts} $y lineto stroke\n";
}

sub verticalLine {
  my ($graph, $x, $style) = @_;
  $x = $x * $graph->{xScale} + $graph->{xOffset};
  $graph->{ps} .= applyStyle($style) .  "$x $graph->{y0pts} moveto $x $graph->{y1pts} lineto stroke\n";
}
 
sub line {
  my ($graph, $x1,$y1,$x2,$y2, $style) = @_;
  $x1 = $x1 * $graph->{xScale} + $graph->{xOffset};
  $x2 = $x2 * $graph->{xScale} + $graph->{xOffset};
  $y1 = $y1 * $graph->{yScale} + $graph->{yOffset};
  $y2 = $y2 * $graph->{yScale} + $graph->{yOffset};
  $graph->{ps} .= applyStyle($style) .  "$x1 $y1 moveto $x2 $y2 lineto stroke\n";
}

sub lineplot {
  my ($graph, $x, $y, $style) =  @_;
  my $xScale = $graph->{xScale};
  my $yScale = $graph->{yScale};
  my $xOffset = $graph->{xOffset};
  my $yOffset = $graph->{yOffset};
  print STDERR "$xScale, $yScale, $xOffset, $yOffset\n";

  my @x = @{$x};
  my @y = @{$y};
  
  my $xstr = "[";
  my $ystr = "[";
  for my $x (@x) {
    $xstr .= ($x * $xScale + $xOffset) . ' ';
  }

  for my $y (@y) {
    $ystr .= ($y * $yScale + $yOffset) . ' ';
  }
  $graph->{ps} .= applyStyle($style) . $xstr . '] ' . $ystr . "] lineplot\n"; 
}

sub markerplot {
  my ($graph,$x, $y, $style, $scale, $marker) =  @_;
  my $xScale = $graph->{xScale};
  my $yScale = $graph->{yScale};
  my $xOffset = $graph->{xOffset};
  my $yOffset = $graph->{yOffset};


  my @x = @{$x};
  my @y = @{$y};
  
  my $xstr = "[";
  my $ystr = "[";
  for my $x (@x) {
    $xstr .= $x * $xScale + $xOffset . ' ';
  }

  for my $y (@y) {
    $ystr .= $y * $yScale + $yOffset . ' ';
  }
  $graph->{ps} .= applyStyle($style) . $xstr . '] ' . $ystr . '] '. $scale . ' /' . $marker . " markerplot\n";
}

sub vectorplot {
  my ($graph, $x, $mag, $angle, $scale) =  @_;
  my $xScale = $graph->{xScale};
  my $yScale = $graph->{yScale};
  my $xOffset = $graph->{xOffset};
  my $yOffset = $graph->{yOffset};
#  print STDERR "$xScale, $yScale, $xOffset, $yOffset\n";

  my @x = @{$x};
  my @mag = @{$mag};
  my @angle = @{$angle};
  my $debug = 1;
  
  my $xstr = "[";
  my $magstr = "[";
  my $anglestr = "[";
  for my $x (@x) {
    $xstr .= sprintf("%6f ",($x * $xScale + $xOffset));
	 if ($debug) {$xstr .= "\n";}
  }

  for my $mag (@mag) {
    $magstr .= sprintf("%6f ", ($mag * $yScale + $yOffset));
	 if ($debug) {$magstr .= "\n";}
  }
  for my $angle (@angle) {
    $anglestr .= sprintf("%6f", $angle);
	 if ($debug) {$anglestr .= "\n";}
  }
  $graph->{ps} .= $xstr . '] ' . $magstr . '] ' . $anglestr . "] $scale /a1 vectorplot\n"; 
}

sub markerplot {
  my ($graph,$x, $y, $style, $scale, $marker) =  @_;
  my $xScale = $graph->{xScale};
  my $yScale = $graph->{yScale};
  my $xOffset = $graph->{xOffset};
  my $yOffset = $graph->{yOffset};


  my @x = @{$x};
  my @y = @{$y};
  
  my $xstr = "[";
  my $ystr = "[";
  for my $x (@x) {
    $xstr .= $x * $xScale + $xOffset . ' ';
  }

  for my $y (@y) {
    $ystr .= $y * $yScale + $yOffset . ' ';
  }
  $graph->{ps} .= applyStyle($style) . $xstr . '] ' . $ystr . '] '. $scale . ' /' . $marker . " markerplot\n";
}




sub includeEPS {
  my ($epsfile, $x, $y) = @_;
  print <<EOF
$x $y  translate
gsave
5 dict begin
  /showpage {} def
  /setpagedevice /pop load def
  exch
EOF
;
  open (EPS, $epsfile) || die "can't open eps file: $epsfile\n";
  while (my $line = <EPS>) {
    print $line;
  }
  close(EPS);
print <<EOF
end
grestore
EOF
;
}

sub setRGB {
  my ($bgcolor) = @_;
  return "$bgcolor setrgbcolor\n";
}

sub drawTicks {
  my ($min, $inc, $count, $tick0, $tick1, $m, $a, $tickname) = @_;
  return "$min $inc $count $tick0 $tick1 $m $a  $tickname\n";
}

sub graph {
  my ($xmin, $xmax, $ymin, $ymax, $x0pts, $x1pts, $y0pts, $y1pts, $box, $bgcolor) = @_;
  if ($xmax < $xmin) {
    my $temp = $xmax;
    $xmax = $xmin;
    $xmin = $temp;
  }

  if ($ymax < $ymin) {
    my $temp = $ymax;
    $ymax = $ymin;
    $ymin = $temp;
  }

  my $boxColor = "0 0 0";
  my $gt = "%graph\n" . setRGB($bgcolor); # set background color of box
  $gt .= "$x0pts $y0pts $x1pts $y1pts fillRect\n"; # initially blank out area of graph
  if ($box) {
    $gt .= setRGB($boxColor);
    $gt .= "$x0pts $y0pts $x1pts $y1pts drawRect\n"; # initially blank out area of graph
  }

  my $tickSize = $x1pts - $x0pts < $y1pts - $y0pts ?.04 * ($x1pts - $x0pts): .04 * ($y1pts - $y0pts);
  my $yTickSize = my $xTickSize = $tickSize;

  my $xScale = ($x1pts - $x0pts) / ($xmax - $xmin);
  my $xOffset = $x0pts - $xmin * $xScale;

  my $yScale = ($y1pts - $y0pts) / ($ymax - $ymin);
  my $yOffset = $y0pts - $ymin * $yScale;

  my $numXTicks = 12;

  my $xinc = ($xmax - $xmin) / $numXTicks;
#  my $yinc = ($ymax - $ymin) / $numYTicks;

  $gt .= drawTicks($xmin, $xinc, $numXTicks, $y0pts, $y0pts + $yTickSize, $xScale, $xOffset, "xtick");
  $gt .= drawTicks($xmin, $xinc, $numXTicks, $y1pts, $y1pts - $yTickSize, $xScale, $xOffset, "xtick");
  $gt .= drawTickNumberX($xmin, $xinc, $numXTicks, $y0pts-15, $xScale, $xOffset, "%02d");
  my @good_dens = (.25, .5, 1, 2, 2.5, 3, 4, 5, 10, 15, 20, 25, 30);
  my ($ymin, $yinc, $numYTicks) = niceNumbers($ymin, $ymax, 6, @good_dens);
  $gt .= drawTicks($ymin, $yinc, $numYTicks, $x0pts, $x0pts + $xTickSize, $yScale, $yOffset, "ytick");
  $gt .= drawTicks($ymin, $yinc, $numYTicks, $x1pts, $x1pts - $xTickSize, $yScale, $yOffset, "ytick");
  $gt .= drawTickNumberY($ymin, $yinc, $numYTicks, $x0pts-25, $yScale, $yOffset, "%3.1f");
  return { ps=>$gt, xScale=>$xScale, yScale=>$yScale, xOffset=>$xOffset, yOffset=>$yOffset,
  			  x0pts=>$x0pts, y0pts=>$y0pts, x1pts=>$x1pts, y1pts=>$y1pts } ;
}

sub drawTickNumberX  {
	my ($xmin, $xinc, $count, $ypts, $xScale, $xOffset, $fmt) = @_;
	my $temp = "[ ";
	for (my $i = 0; $i <= $count; $i++) {
		$temp .= sprintf('('.$fmt.')', $xmin + $i * $xinc);
	}
	my $xpts = $xmin * $xScale + $xOffset;
	my $dx = $xinc * $xScale;
	return $temp .= "] $dx 0 $xpts $ypts displayTextBlock \n"; 
}
sub drawTickNumberY  {
	my ($ymin, $yinc, $count, $xpts, $yScale, $yOffset, $fmt) = @_;
	my $temp = "[ ";
	for (my $i = 0; $i <= $count; $i++) {
		$temp .= sprintf('('.$fmt.')', $ymin + $i * $yinc);
	}
	my $ypts = $ymin * $yScale + $yOffset;
	my $dy = $yinc * $yScale;
	return $temp .= "] 0 $dy $xpts $ypts displayTextBlock \n"; 
}
sub tileGraphs {
  my ($graphSpec, $textStyle, $x, $y, $w, $h, $dx, $dy, $numRows, $numCols, $colMajor) = @_;
  my $gt = applyTextStyle($textStyle);
  foreach my $g (@{$graphSpec}) {
    $gt .=  $g->{pos} . ' moveto (' . $g->{title} . ") show\n";
    
  }
  return $gt;
}
sub niceNumbers {
	my ($min, $max, $max_ticks, @good_denominators) = @_;
	my $range = $max - $min;
	for (my $i = 0; $i < @good_denominators; $i++) {
		my $den = $good_denominators[$i];
		if ($range / $den <= $max_ticks) {
			my $nice_min = floor($min / $den) * $den;
			my $nice_max = ceil($max / $den) * $den;
			if (($nice_max - $nice_min) / $den > $max_ticks and
					$i < $#good_denominators) {
					$den = $good_denominators[$i+1];
				 	$nice_min = floor($min / $den) * $den;
					$nice_max = ceil($max / $den) * $den;
			}

			my $count = ceil(($nice_max - $nice_min) / $den) ;
			print STDERR "$nice_min, $den, $count\n";
			return ($nice_min, $den, $count);
		}
	}
	
}
1;
