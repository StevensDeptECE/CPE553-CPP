use strict;
my $width = 1224;
my $height = 792;
my $n = 20;
my $border = 20;
my $xmin = $border;
my $xmax = $width - $border;
my $ymin = $border;
my $ymax = $height - $border;
my $dx = ($xmax - $xmin) / $n;
my $dy = ($ymax - $ymin) / $n;

print <<EOF
%!PS-Adobe-3.0
%%Title: TableGen
%%For:
%%Creator: Dov Kruger using Graphite Library1.0
%%CreationDate: 2008-11-18
%%BoundingBox: 20.000000 20.000000 1204.000000 772.000000 
%%DocumentData: Clean7Bit
%%Orientation: Landscape
%%Pages: 0d
%%PageOrder: Ascend
%%DocumentMedia: Tabloid 1224 792 0 () ()
%%DocumentNeededResources
%%DocumentProcessColors: Color
%%EndComments
%%BeginProlog
%%Copyright: (c)2008 Dov Kruger
%%EndProlog
%%BeginSetup
%%EndSetup
%%Page: (1) 1
%%BeginPageSetup
<< /PageSize [1224 792] >> setpagedevice
<< /MaxOpStack 300000 >> setuserparams
%%EndPageSetup
/bigFont { /Helvetica-Bold findfont 24 scalefont setfont } def
/smallFont { /Helvetica findfont 20 scalefont setfont } def
/str 20 string def
EOF
    ;
my $borderColor = "0 .7 .1 setrgbcolor";
my $regColor = "0 0 0 setrgbcolor";
my $y = $ymin;
my $numLines = $n + 1;
for (my $i = 0; $i <= $numLines; $i++, $y += $dy) {
    print "$xmin $y moveto $xmax $y lineto stroke\n";
}
my $x = $xmin;
#my $ymax = $xmin + $numLines * $dx;
for (my $i = 0; $i <= $numLines; $i++, $x += $dx) {
    print "$x $ymin moveto $x $ymax lineto stroke\n";
}

my $shiftX = 10;
my $shiftY = 10;
$xmin += $shiftX;
$xmax += $shiftX;
$ymin += $shiftY;
$ymax += $shiftY;
my $y = $ymax - $dy;

my $x = $xmin;
print "bigFont $borderColor $x $y moveto (x) show ";
$x += $dx;
for (my $j = 1; $j <= $n; $j++, $x += $dx) {
	print "$x $y moveto $j str cvs show ";
    }
print "\n";
$y -= $dy;
for (my $i = 1; $i <= $n; $i++, $y -= $dy) {
    my $x = $xmin;
    print "bigFont $borderColor $x $y moveto $i str cvs show $regColor smallFont ";
    $x += $dx;
    for (my $j = 1; $j <= $n; $j++, $x += $dx) {
	print "$x $y moveto ", $i*$j," str cvs show ";
    }
    print "\n";
}
