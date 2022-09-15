use strict;

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

sub lineplot {
  my ($x, $y, $multiplierX, $addifierX, $multiplierY, $addifierY, $style) =  @_;

  my @x = @{$x};
  my @y = @{$y};
  
  my $xstr = "[";
  my $ystr = "[";
  for my $x (@x) {
    $xstr .= $x * $multiplierX + $addifierX . ' ';
  }

  for my $y (@y) {
    $ystr .= $y * $multiplierY + $addifierY . ' ';
  }
  return applyStyle($style) . $xstr . '] ' . $ystr . '] lineplot';
}

sub markerplot {
  my ($x, $y, $multiplierX, $addifierX, $multiplierY, $addifierY, $scale, $marker, $style) =  @_;

  my @x = @{$x};
  my @y = @{$y};
  
  my $xstr = "[";
  my $ystr = "[";
  for my $x (@x) {
    $xstr .= $x * $multiplierX + $addifierX . ' ';
  }

  for my $y (@y) {
    $ystr .= $y * $multiplierY + $addifierY . ' ';
  }
  return applyStyle($style) . $xstr . '] ' . $ystr . '] '. $scale . ' /' . $marker . " markerplot\n";
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
  my ($min, $inc, $max, $tick0, $tick1, $m, $a, $tickname) = @_;
  return "$min $inc $max $tick0 $tick1 $m $a  $tickname\n";
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
  my $gt = setRGB($bgcolor); # set background color of box
  $gt .= "$x0pts $y0pts $x1pts $y1pts fillRect\n"; # initially blank out area of graph
  if ($box) {
    $gt .= setRGB($boxColor);
    $gt .= "$x0pts $y0pts $x1pts $y1pts drawRect\n"; # initially blank out area of graph
  }

  my $xTickSize = .02 * ($x1pts - $x0pts);
  my $yTickSize = .02 * ($y1pts - $y0pts);

  my $xScale = ($x1pts - $x0pts) / ($xmax - $xmin);
  my $xOffset = $x0pts - $xmin * $xScale;

  my $numXTicks = 5;
  my $numYTicks = 5;

  my $xinc = ($xmax - $xmin) / $numXTicks;
  my $yinc = ($ymax - $ymin) / $numYTicks;

  $gt .= drawTicks($xmin, $xinc, $xmax, $y0pts, $y0pts + $yTickSize, $xScale, $xOffset, "xtick");
  $gt .= drawTicks($xmin, $xinc, $xmax, $y1pts, $y1pts - $yTickSize, $xScale, $xOffset, "xtick");
  return $gt;
}

sub tileGraphs {
  my ($graphSpec, $textStyle, $x, $y, $w, $h, $dx, $dy, $numRows, $numCols, $colMajor) = @_;
  my $gt = applyTextStyle($textStyle);
  foreach my $g (@{$graphSpec}) {
    $gt .=  $g->{pos} . ' moveto (' . $g->{title} . ") show\n";
    
  }
  return $gt;
}

#header("Tabloid", "Landscape",20);
header("Letter", "Landscape",20);
#header("Letter", "Portrait",20);

my $pagenum = 0;
#for (my $pagenum = 0; $pagenum <= $#ARGV; $pagenum++) {
  pageprolog($pagenum+1);
#  open(PAGE, $ARGV[$pagenum]) || die("can't open $ARGV[$pagenum]\n");
#  while (my $line = <PAGE>) {
#      $line =~ s/\$(\w+)/$vars{$1}/g;
#      print $line;
#  }

#  includeEPS("logo.eps", 200,200);

my $x = [1, 2, 3, 4, 5];
my $y = [15.2, 16.1, 17.1, 15.7, 15.2];
my $gt = graph(1, 5, 14, 18, 0, 500, 300, 600, 1, ".6 .8 .8");
my $style3DashRed = {"linewidth"=>3, "linecolor" => "1 0 0",  "dashstyle" => "[2 5] 0" };
my $style3DashBlue = {"linewidth"=>3, "linecolor" => "0 0 1",  "dashstyle" => "[2 5] 0" };
my $style3DashBlack = {"linewidth"=>3, "linecolor" => "0 0 0",  "dashstyle" => "[2 5] 0" };
my $style3DashGreen = {"linewidth"=>3, "linecolor" => "0 1 0",  "dashstyle" => "[2 5] 0" };

my $styleSolidBlue = {"linewidth"=>0, "linecolor" => "0 0 1",  "dashstyle" => "[] 0" };
my $styleSolidBlack = {"linewidth"=>0, "linecolor" => "0 0 0",  "dashstyle" => "[] 0" };
my $styleSolidRed = {"linewidth"=>0, "linecolor" => "0 0 0",  "dashstyle" => "[] 0" };

my $styleSolid = {"linewidth"=>.1, "linecolor" => "1 0 0",  "dashstyle" => "[] 0" };

my $lineplot = lineplot($x, $y, 100, 0, 20, 50, $styleSolidBlack);
my $markerplot = markerplot($x, $y, 100, 0, 20, 50, 4, 'markerx', $styleSolidBlue);

my $defaultStyle = applyStyle($styleSolidBlue);
my $blueSolid = applyStyle($styleSolidBlack);

print <<EOF
$gt
0 0 0 setrgbcolor
3 setlinewidth

$lineplot
$markerplot
%50 100 50 markerx
%50 200 50 markersquare
%50 300 50 markercircle
0 0 0 setrgbcolor
/Helvetica 24 selectFont
%200 550 moveto (This is the TITLE) show
$blueSolid
[(a) (b) (hello) (there)] 0 -20 20 400 displayTextBlock
EOF
;


=comment
%200 200 300 300 fillRect
%1 0 0 setrgbcolor
%300 500 400 600 drawRect
%0 0 1 setrgbcolor
%0 350 350 simpleArrow
%.1 setlinewidth
%30 150 350 350 scaledSimpleArrow

%400 100 100 100 20 fillRoundRect
%1 0 0 setrgbcolor
%0 setlinewidth
%[5 5] 0 setdash
%1 1 5 340 350 100 0 xtick
%14 1 18 550 565 20 50 ytick

=cut
  pagetrailer();
#}
trailer();
