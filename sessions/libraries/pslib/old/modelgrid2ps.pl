#!/usr/bin/perl

use strict;
my $line=<>;
$line=<>;
my $depth = <> + 0;
for (my $i = 0; $i < $depth; $i++) {
  $line=<>;
}
$line = <>;
my $x = [];
my $y = [];
my $depth = [];
my ($garb, $cols, $rows) = split(/\s+/, <>);
my $h = 5;
while ($line = <>) {
  my ($garb,$i, $j, $h1, $h2, $h, $ang, $lat, $lon, $garb) = split(/\s+/, $line);
  my ($garb,$i, $j, $dx,$dy, $lon, $lat,$garb2) = split(/\s+/, $line);
#print "lon: $lon  $lat\n";
  $$x[$i][$j] = $lon;
  $$y[$i][$j] = $lat;
  $$depth[$i][$j] = $h;
}

print "/grid [\n";
for (my $j = 0; $j < $rows; $j++) {
  for (my $i = 0; $i < $cols; $i++) {
    if (exists($$x[$i][$j])) {
      print "[$$x[$i][$j] $$y[$i][$j] $$depth[$i][$j]]";
    } else {
      print "[]";
    }
  }
  print "\n";
}
print "] def\n";
