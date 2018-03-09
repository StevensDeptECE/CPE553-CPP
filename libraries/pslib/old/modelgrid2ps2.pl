#!/usr/bin/perl

use strict;
my $line=<>;
$line=<>;
my $kb = <> + 0;
for (my $i = 0; $i < $kb; $i++) {
  $line=<>;
}
$line = <>;
my $x = [];
my $y = [];
my ($garb, $cols, $rows) = split(/\s+/, <>);
my $h = 5;
while ($line = <>) {
  my ($garb,$i, $j, $dx,$dy, $lon, $lat,$garb2) = split(/\s+/, $line);
#print "lon: $i $j $lon  $lat\n";
  $$x[$i][$j] = $lon;
  $$y[$i][$j] = $lat;
#  $$depth[$i][$j] = $h;
}
open (GRID, 'model_grid');
$line = <GRID>;
$line=<GRID>;
#line = <GRID>;#$depth = <GRID> + 0;
for (my $i = 0; $i < $kb; $i++) {
  $line=<GRID>;
}
$line = <GRID>;
my $depth = [];
$line = <GRID>;
$line = <GRID>;
#my ($garb, $cols, $rows) = split(/\s+/, <GRID>);
my $h = 5;
while ($line = <GRID>) {
  my ($garb,$i, $j, $h1, $h2, $h, $ang, $lat, $lon, $garb) = split(/\s+/, $line);

  $$depth[$i][$j] = $h;
#  print "$i $j $$depth[$i][$j]\n";
}
close(GRID);
print "/grid [\n";
for (my $j = 24; $j < 40; $j++) {
  for (my $i = 2; $i < 10; $i++) {
#    if (exists($$x[$i][$j])) {
      print "$$x[$i][$j] $$y[$i][$j] $$depth[$i][$j] ";
#    }
  }
  print "\n";
}
print "] def\n";
