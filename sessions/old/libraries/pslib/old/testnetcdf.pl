use strict;
use NetCDF;

my $file = $ARGV[0] ? $ARGV[0] : "gcmplt.cdf";
my $nc = NetCDF::open($file, NetCDF::NOCLOBBER) || die"Failed opening netcdf file $file\n";
my $varid = NetCDF::varid($nc, "salt");

my ($numDims, $numVars, $numAtts, $recDim);
NetCDF::inquire($nc, $numDims, $numVars, $numAtts, $recDim);
print "numbers: $numDims $numVars $numAtts $recDim\n";
my ($dimname, $size);
for (my $i = 0; $i < $numDims; $i++) {
  NetCDF::diminq($nc, $i, $dimname, $size);
  print "dimension: $i $dimname  [$size]\n";
}

my $varname = "";
my $datatype = "";
my $ndims = 0;
my $dimids = [];
my $numAttsInVar;
for (my $i = 0; $i < $numVars; $i++) {
  print "var # $i\n";
  NetCDF::varinq($nc, $i, $varname, $datatype, $ndims, $dimids, $numAttsInVar);
  print "$i $varname $datatype $ndims $dimids->[$i]\n";
}
#  NetCDF::varinq($nc, $i, $varname, $datatype
my $im = 59;
my $jm = 94;
my $foo = [];
my $status = NetCDF::varget($nc, $varid, [0,0,0,0], [1,1,$jm,$im], $foo);
print "status=$status\n";
my $n = @{$foo};
print "size=$n\n";
