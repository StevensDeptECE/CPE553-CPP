#!/usr/bin/perl
use strict;
use POSIX;

#
# Graphite2d: Postscript Layout Generation in Perl
# (c) Feb. 2007, Dov Kruger
#

sub dateNow {
    my ($sec, $min, $hour, $day, $month, $year, $weekday, $dayofyear,$isdst) = localtime();
    return sprintf("%4d/%02d/%02d %02d:%02d:%02d",$year+1900,$month+1,$day, $hour, $min, $sec);
}

my %doc_info = (
  version=>"Graphite2d 0.4",
  title => "", creator => "", author => "", copyright => "",
  creation => dateNow(),
  stackSize => 300000,
  libraries => [ "timeseries.ps" ],
  layout => {
    left_margin => 10,
    right_margin => 10,
    top_margin => 10,
    bot_margin => 10,
    num_cols => 1,
    row_sizes => [],
    num_rows => 6,
    col_sizes => [],
    box=>0,
  },
  page_width => 612,
  page_height => 792
);

# variables substituted in text of postscript file $xxx =>value
#my %vars = (
#  graphite => $doc_info->{version},
#  width => $doc_info->{page_width},
#  height => $doc_info->{page_height}
#);

sub buildDocument {
  my ($doc_info, $pageSizeName, $orientation, $title, $author, $copyright) = @_;
  my %doc = %{$doc_info};

  setPageSize(\%doc, $pageSizeName, $orientation);
  buildHeader(\%doc);

  my $libraries = "";
  foreach my $library (@{$doc_info->{libraries}}) {
    open(LIB, $library) || die "Failed to open file $library\n";
    my @librarycode = <LIB>;
    $libraries .= join("",@librarycode);
    close(LIB);
  }
  print $libraries;
  $doc{library_code} = $libraries;

  return \%doc;
}

sub setPageSize {
   my ($doc, $pageSizeName, $orientation) = @_;
   my %pageSizes = ("Letter", [612,792], "Legal", [612, 1008], "Tabloid", [792,1224]);
   my $psize = $pageSizes{$pageSizeName};
   my $w = ($orientation eq "Landscape") + 0;
   print STDERR "w=$w\n";
   $doc->{page_width} =  $psize->[1-$w];
   $doc->{page_height} =  $psize->[$w];
   $doc->{page_size} = $pageSizeName;
   $doc->{orientation} = $orientation;

#   $vars{"boundBox"} = $boundBox;
#   $vars{"date"} = $creationDate;
}

sub buildHeader {
    my ($doc) = @_;
    
print <<EOF
%!PS-Adobe-3.0
%%Title: $doc->{title}
%%For:
%%Creator: $doc->{version}
%%CreationDate: $doc->{creationDate}
%%BoundingBox: $doc->{boundBox}
%%DocumentData: Clean7Bit
%%Orientation: $doc->{orientation}
%%Pages: 1
%%PageOrder: Ascend
%%DocumentMedia: $doc->{sizeName} $doc->{pageWidth} $doc->{pageHeight} 0 () ()
%%DocumentNeededResources
%%DocumentProcessColors: Color
%%EndComments
%%BeginProlog
%%Copyright: $doc->{copyright}
%%EndProlog
%%BeginSetup
%%EndSetup
EOF
;
}

sub pageprolog {
    my ($doc, $pagenum) = @_;
print<<EOF
%%Page: ($pagenum) $pagenum
%%BeginPageSetup
<< /PageSize [$doc->{pageWidth} $doc->{pageHeight}] >> setpagedevice
<< /MaxOpStack $doc->{stackSize} >> setuserparams
%%EndPageSetup
EOF
;
}

sub newPage {
#print STDERR "newpage!\n";
print <<EOF
showpage
%%Trailer
%%EOF
EOF
;
}

sub buildLayout {
  my ($doc, $margin, $num_cols, $num_rows) = @_;
  my $layout = {
    left_margin => $margin,
    right_margin => $margin,
    top_margin => $margin,
    bot_margin => $margin,
    num_cols => $num_cols,
    num_rows => $num_rows,
    box => 0
    };
  $doc->{layout} = $layout;

  my $active_width = $doc->{page_width} - $layout->{left_margin} - $layout->{right_margin};
  my $active_height = $doc->{page_height} - $layout->{top_margin} - $layout->{bot_margin};
print STDERR "active $active_width, $active_height\n";
  my $col_size = $active_width / $num_cols;
  my $row_size = $active_height / $num_rows;
print STDERR "size col= $col_size, $row_size\n";
  my @col_sizes = ();
  for (my $i = 0; $i < $num_cols; $i++) {
    push(@col_sizes, $col_size);
  }

  my @row_sizes = ();
  for (my $i = 0; $i < $num_rows; $i++) {
    push(@row_sizes, $row_size);
  }

  my @col_startx = ();
  my $x = $layout->{left_margin};
  for (my $i = 0; $i < @col_sizes; $i++, $x += $col_size) {
    push(@col_startx, $x);
  }

  my @row_starty = ();
  my $y = $doc->{page_height} - $layout->{top_margin} - $row_size;
  for (my $i = 0; $i < @row_sizes; $i++, $y -= $row_size) {
    push(@row_starty, $y);
  }
  $layout->{num_rows} = $num_rows;
  $layout->{num_cols} = $num_cols;
  $layout->{col_startx} = \@col_startx;
  $layout->{row_starty} = \@row_starty;
  $layout->{col_sizes} = \@col_sizes;
  $layout->{row_sizes} = \@row_sizes;
}

sub getBoundingBox {
  my ($doc) = @_;
  my $layout = $doc->{layout};
  my $box = $layout->{box};
  if ($box >= $layout->{num_cols} * $layout->{num_rows}) {
    $box = $layout->{box} = 0;
    newPage();
  }
#  print STDERR "box=$box\n";
  my $row = floor($box / $layout->{num_cols});
  my $col = $box % $layout->{num_cols};
  my $bounds = {
    x => $layout->{col_startx}[$col],
    y => $layout->{row_starty}[$row],
    width => $layout->{col_sizes}->[$col],
    height => $layout->{row_sizes}->[$row]
  };
  $layout->{box}++;
  return $bounds;
}

sub includeEPS {
  my ($doc, $epsfile, $x, $y) = @_;

  printf <<EOF
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

my $doc = buildDocument(\%doc_info, "Letter", "Portrait", "test", "Dov Kruger", "(c)2007 Dov Kruger");
#my $doc = buildDocument(\%doc_info, "Letter", "Landscape", "test", "Dov Kruger", "(c)2007 Dov Kruger");

my $numBoxes = 20;
buildLayout($doc, 10, 1, 6);
for (my $i = 0; $i < $numBoxes; $i++) {
  my $boundingBox = getBoundingBox($doc);
#  print "[$boundingBox->{x},$boundingBox->{y} $boundingBox->{width} $boundingBox->{height}]\n";
  print 'gsave '.$boundingBox->{x}.' ' .$boundingBox->{y}.' translate 0 0 '.
    $boundingBox->{width} .' '.$boundingBox->{height}." drawRect grestore\n";
  print "% $doc->{layout}{box}\n";
}
