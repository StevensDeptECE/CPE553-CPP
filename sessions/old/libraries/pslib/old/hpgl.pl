#!/usr/bin/perl

use strict;

my ($line, $newline, $comma, $x, $y);

my ($sx,$ax, $sy, $ay) = scalehpgl(-75,-71,38,41,50000,50000);
my $ESC = "\x1d";
print "$ESC.(;$ESC.I81;;17:.$ESC.N;19:.IN;SC;PU;SP1;LT;VS36;\n";
for (my $count = 0; $line = <>; $count++) {
    if ($line =~ /nan/) {
	$newline = 1;
	$comma = 0;
#	if ($count >1000) { exit(0); }
    } else {
	($x,$y) = split(/\s+/, $line);
	$x = ($x + $ax) * $sx;
	$y = ($y + $ay) * $sy;
	if ($newline) {
	    print "PU$x,${y};\nPD";
	    $newline = 0;
	} else {
	    printf ($comma ? ",%8f,%8f" : "%8f,%8f", $x,$y);
	    $comma = 1;
	}
    }
}

sub scalehpgl {
    my ($x1, $x2, $y1, $y2, $plotx, $ploty) = @_;
    my $dx = $x2 - $x1;
    my $dy = $y2 - $y1;
    my $ax = -$x1 + 0;
    my $ay = -$y1 + 0;
    my $sx = $plotx / $dx;
    my $sy = $ploty / $dy;
    return ($sx, $ax, $sy, $ay);
}
