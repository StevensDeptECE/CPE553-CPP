use strict;

my ($title, $creator, $author, $copyright);

my $version = 0.1;
my @libraries = ("library.ps", "graphite.ps","grid2old.ps", "map.ps");
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


header("Tabloid", "Landscape",20);
#header("Letter", "Landscape",20);
#header("Letter", "Portrait",20);

for (my $pagenum = 0; $pagenum <= $#ARGV; $pagenum++) {
  pageprolog($pagenum+1);
  open(PAGE, $ARGV[$pagenum]) || die("can't open $ARGV[$pagenum]\n");
  while (my $line = <PAGE>) {
      $line =~ s/\$(\w+)/$vars{$1}/g;
      print $line;
  }
  pagetrailer();
}
trailer();
