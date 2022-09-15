use strict;

print "/coast [\n";

my $inList = 0;
while (my $line=<>) {
    if ($line =~ /nan/) {
	print "]\n[";
    } else {
	if ($inList) {
	    print ",";
	}
#	chomp $line;
#	my ($x,$y) = split(/\s+/, $line);
#	print $x . "," . $y;
	$line =~ s/\s+/ /g;
	print $line;
    }
    
}
print "] def\n";
