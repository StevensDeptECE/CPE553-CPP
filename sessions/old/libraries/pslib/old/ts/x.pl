#!/usr/bin/perl
#
use strict;

require "./functions2.pl";


my $x1 = localtime();
print "$x1\n";

my $v1 = '  23  43';
my $v2 = ' 34.3  ';
my $v3 = '    ';

if ($v1 =~ /\d+/) {
	print "v1: $v1\n";
}
if ($v2 =~ /\d+/) {
	print "v2: $v2\n";
}
if ($v3 =~ /\d+/) {
	print "v3: $v3\n";
}
if (length($v3) > 0) {
	print "oops\n";
}

for my $i (1..1) {
	print "XXXX\n";
}

my $dt1 = '2007-01-29 10:24:00';
my $ts1 = convert_date_to_seconds($dt1, 18000);
my $dt2 = convert_seconds_to_date($ts1);
print "dt1, dt2: $dt1, $dt2\n";

my @v1 = (34,45);
change(\@v1);
my $int1 = 222;
change_int(\$int1);
print "v1[0]: $v1[0]\n";
print "v1[3]: $v1[3]\n";
print "int1: $int1\n";

print "array v1: @v1\n";
ch(@v1);
print "array v1: @v1\n";

sub ch {
	my (@ar) = @_;
	$ar[3] = 444444;
	print "ch_ar: @ar\n";
}

sub change {
	my ($val) = @_;
	 $val->[0] = 10;
	 push @{$val}, 22;
	 push @{$val}, 33;
	 push @{$val}, 44;
#	 $val->[1] = 11;
#	 $val->[2] = 12;
#	 $val->[3] = 13;
}
sub change_int {
	my ($val) = @_;
	 ${$val} = 444;
}

