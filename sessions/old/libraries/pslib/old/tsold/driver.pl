#!/usr/bin/perl
require "./functions2.pl";
require "./timeseries.pm";
use strict;
sub get_db_vector_array;

=comment
my($sec, $min, $hour, $day, $mon, $year,$wday,$yday,$isdst) = gmtime();
my $utc_dt =   sprintf("%4d-%02d-%02d %02d:%02d:%02d",$year+1900, ++$mon, $day, $hour, $min, $sec);
my $today8 = sprintf("%4d%02d%02d",$year+1900, $mon, $day);
my $today10 = sprintf("%4d-%02d-%02d",$year+1900, $mon, $day);
my ($start_dt, $end_dt);

my $dbh = connect_specific_DB('davidson', 'dl', 'mysql', 'kn1ght');
my $for_real = 1;
my $print_sql = 1;
my $web_or_files  = $ARGV[0];
my $dir  = '/home/drunnels/nos';
my $latest_dt;

my ($latest_pwl_dt, $latest_tide_dt, $latest_bwl_dt, $latest_pwl_val, $latest_bwl_val, $latest_tide_val);
my ($db_latest_pwl_dt, $db_latest_bwl_dt, $db_latest_tide_dt);

my $months_file = read_entire_file('months.txt');
my @months = split(/\n/, $months_file);

#my $dir  = $ARGV[1];
=cut


my $dbh_davidson = connect_specific_DB('davidson', 'dl', 'mysql', 'kn1ght');
my $dbh_atlas = connect_specific_DB('atlas', 'dl', 'dl_reader', 'BIGre3der');
my $model_date = convert_date_to_seconds('2007-01-21 00:00:00');

my $base_date = '2007-01-27';
my $start_date='2007-01-27';
my $end_date='2007-01-29 23:59:59';
my $starting_hours = convert_date_to_seconds("$start_date 00:00:00");
my $styleSolidBlue = {"linewidth"=>0, "linecolor" => "0 0 1",  "dashstyle" => "[] 0" };
my $styleSolidBlack = {"linewidth"=>0, "linecolor" => "0 0 0",  "dashstyle" => "[] 0" };

my $data_sql = "select d, type, val from data where d between '$start_date 00:00:00' and '$end_date 23:59:59'" .
	" and type = 'WTMP' and sid = 'CTD1'" ;
my $data2_sql = "select d, val from data where d between '$start_date 00:00:00' and '$end_date 23:59:59'" .
	" and type = 'SALT' and sid = 'CTD1'" ;
my $atlas_wind_sql = " select dt, param, val from ext_data where " .
	" param in ('WSPD', 'WD') and sid = 'N004' and " .
	" dt between '$start_date' and '$end_date' " .
	" order by sid, dt, param desc ";

my @dt_arr;
my @val_arr;
my @mag_arr;
my @dir_arr;

my ($dt_found_min, $dt_found_max, $mag_found_min, $mag_found_max);
#my ($dt_found_min, $dt_found_max, $mag_found_min, $mag_found_max) =
#		get_db_scalar_array ($dbh_davidson, $data_sql, \@dt_arr, \@val_arr, 0);
#for (my $i = 0; $i <= $#dt_arr; $i++) {
#	print "date: $dt_arr[$i]\t\tval $val_arr[$i]\n";
#}
	my ($dbh, $sql, $dt_arr, $magnitude_arr, $dir_arr, $param1, $param2, $convert)  = @_;
 ($dt_found_min, $dt_found_max, $mag_found_min, $mag_found_max) =
		get_db_vector_array ($dbh_atlas, $atlas_wind_sql, \@dt_arr, \@mag_arr, ,\@dir_arr, 'WSPD', 'WD', 0);
#for (my $i = 0; $i <= $#dt_arr; $i++) {
	#print STDERR "date: $dt_arr[$i]\t\tmag: $mag_arr[$i]\t\tdir: $dir_arr[$i]\n";
#}

=comment
print STDERR "sql=$data_sql\n";
$dbc = $dbh->prepare($data2_sql);
$dbc->execute;
my (@date_ar2, @val_ar2);
my ($dt2, $val12);
while (($dt2, $val2) = $dbc->fetchrow_array) {
	my $hours2 = ((convert_date_to_seconds($dt2) - $starting_hours) /3600) -24;
	push @date_ar2, $hours2;
	push @val_ar2, $val2;
}
=cut
header("Tabloid", "Landscape",20);
#header("Letter", "Landscape",20);
pageprolog(1);

print "/Helvetica 12 selectFont\n";
print STDERR "$mag_found_min, $mag_found_max\n";
my $gt = graph(0, 48, $mag_found_min, $mag_found_max, 75, 1200, 500, 750, 1, ".8 .9 .9");
#my $gt = graph(-24, 48, $mag_found_min, $mag_found_max, 50, 782, 502, 602, 1, ".8 .9 .9");
vectorplot($gt, \@dt_arr, \@mag_arr, \@dir_arr, 20);
verticalLine($gt, 24, $styleSolidBlue);
print $gt->{ps};

#my $gt2 = graph(-24, 48, 0, 30, 50, 782, 302, 402, 1, ".8 .9 .9");

#print STDERR "gt=$gt->{yOffset}\n\n";
#print STDERR "gt2=$gt2->{yOffset}\n\n";

#lineplot($gt2, \@date_ar2, \@val_ar2, $styleSolidBlue);
#print $gt2->{ps};

#markerplot($gt, \@date_ar, \@val_ar, $styleSolidBlue, 4, 'markerx');
print <<EOF
0 setlinewidth
[] 0 setdash
0 0 0 setrgbcolor
EOF
;
pagetrailer();
trailer();


# sql must request dt, param,
# dbh: in, sql: in, dt_arr: out, $val_arr out,
# 	 return $dt_found_min, $dt_found_max, $val_found_min, $val_found_max
sub get_db_scalar_array {
	my ($dbh, $sql, $dt_arr, $val_arr) = @_;
	my ($dt_found_min, $dt_found_max, $val_found_min, $val_found_max);
	my $first_time = 1;
	my $dbc = $dbh->prepare($sql);
	$dbc->execute;
	my ($dt, $param, $val);
	while (($dt, $param, $val) = $dbc->fetchrow_array) {
		if ($first_time) {
			$first_time = 0;
			$dt_found_min = $dt;
			$val_found_min = $val;
			$val_found_max = $val;
		}
		$val_found_min = $val if $val < $val_found_min;
		$val_found_max = $val if $val > $val_found_max;
		push @{dt_arr}, $dt;
		push @{val_arr}, $val;
	}
	$dt_found_max = $dt;
	return [$dt_found_min, $dt_found_max, $val_found_min, $val_found_max];

}
sub get_db_vector_array {
	my ($dbh, $sql, $dt_arr, $magnitude_arr, $dir_arr, $param1, $param2, $convert)  = @_;
	my ($dt_found_min, $dt_found_max, $mag_found_min, $mag_found_max);
	my ($match_dt, $magnitude, $direction, $u, $v);
	my $counter = 0;
	my $first_time = 1;
	my $dbc = $dbh->prepare($sql);
	$dbc->execute;
	my ($dt, $param, $val);
	while (($dt, $param, $val) = $dbc->fetchrow_array) {
		$counter++;
		if ($counter %2) {
			$param eq $param1 or die "found $param expected $param1 on record $counter \n";
			$match_dt = $dt;
			$u = $val;
		}
		else { #2nd record of pair
			$param eq $param2 or die "found $param expected $param2 on record $counter \n";
			$dt eq $match_dt or die "2nd pair date of $dt didn't match $match_dt for record $counter\n";
			$v = $val;
#			print STDERR "u, v: $u, $v\n";
			if ($convert) { #all but winds
				$magnitude = sqrt($u**2 * $v**2);
				$direction = atan2($v, $u);
			}
			else { #winds
				$magnitude = $u;
				$direction = 270 - $v ;
			}
			if ($first_time) {
				$first_time = 0;
				$mag_found_min = $magnitude;
				$mag_found_max = $magnitude;
			}
			else {
				$mag_found_min = $magnitude if $magnitude < $mag_found_min;
				$mag_found_max = $magnitude if $magnitude > $mag_found_max;
			}
			my $hours = (convert_date_to_seconds($dt) - convert_date_to_seconds($base_date)) /3600 ;
			#my $hours = (convert_date_to_seconds($dt) - convert_date_to_seconds($base_date)) /3600 -24;
			push @{dt_arr}, $hours;
			#push @{dt_arr}, $dt;
			push @{$magnitude_arr}, $magnitude;
			push @{$dir_arr}, $direction;
		}	
			
	}
	$dt_found_max = $dt;
	return ($dt_found_min, $dt_found_max, $mag_found_min, $mag_found_max);

}
