#!/usr/bin/perl
use Time::Local;
use LWP::Simple;
use DBI;
use strict;

my %latest; # global hash of all the latest values for each station and type
my %convertor; # convert from one unit to another

#===============================FUNCTIONS=============================
sub connect_DB() {
	my $host = "davidson";
	my $mydb = "dl";
	my $dbuser = "mysql";
	my $dbpass = "kn1ght";
	my $dbh = DBI->connect("DBI:mysql:$mydb:$host", "$dbuser", "$dbpass");
	return $dbh;
}
#===============================FUNCTIONS=============================
sub connect_specific_DB() {
	my ($host, $db, $user, $pw) = @_;
	my $port = '3306';
	my $dbh = DBI->connect("DBI:mysql:$db:$host;port=$port", "$user", "$pw");
	#my $dbh = DBI->connect("DBI:mysql:$db:$host", "$user", "$pw");
	return $dbh;
}
#===============================FUNCTIONS=============================
sub connect_specific_DB2() {
	my ($host, $db, $user, $pw) = @_;
	my $port = '3306';
	my $dbh = DBI->connect("DBI:mysql:$db:$host;port=$port", "$user", "$pw");
	if (!$dbh) {
		print "DBI::err: $DBI::err\t DBI::errstr: $DBI::errstr\n";
	}
	return $dbh;
}
#====================================================================
sub max_date {
	my ($id, $table, $dbh) = @_;
	my $sql = "SELECT max(d) FROM latest_data where sid='$id'";
	print "$sql\n";
	my $dbc = $dbh->prepare($sql);
	$dbc->execute;
	my ($d) = $dbc->fetchrow_array ;
	$dbc->finish;
	return $d;
}
#====================================================================
sub max_date_type {
	my ($id, $table, $dbh, $type) = @_;
	my $sql = "SELECT max(d) FROM  latest_data where sid='$id' and type='$type'";
	my $dbc = $dbh->prepare($sql);
	my $max_d;
	$dbc->execute;
	my ($d) = $dbc->fetchrow_array;
	$dbc->finish;
	return $d;
}
#====================================================================
sub load_params {
	my ($dbh) =@_;
	my $sql = "SELECT type, valid_min, valid_max from data_type";
	my $dbc = $dbh->prepare($sql);
	$dbc->execute;
	my %minmax_hash= ();
	my ($id, $min_val, $max_val);
	while (($id, $min_val, $max_val) = $dbc->fetchrow_array)
	{
		$minmax_hash{$id} = [$min_val, $max_val];
		#print "$minmax_hash{$id}\n";
	}
	$dbc->finish;
	return \%minmax_hash;
}
#====================================================================
sub load_adjuster_hash {
	my ($dbh) =@_;
	my $sql = "SELECT dev, data_type, min_val, max_val, adjust_val_mult, adjust_val_offset" .
			" from dev_sensors";
	my $dbc = $dbh->prepare($sql);
	$dbc->execute;
	my %adjuster_hash= ();
	my ($dev, $data_type, $min_val, $max_val, $adjust_val_mult, $adjust_val_offset);
	while (($dev, $data_type, $min_val, $max_val, $adjust_val_mult, $adjust_val_offset) = $dbc->fetchrow_array){
		$adjuster_hash{$dev.$data_type} = [$min_val, $max_val, $adjust_val_mult, $adjust_val_offset];
	}
	$dbc->finish;
	return \%adjuster_hash;
}
#====================================================================
sub GMT2ET {
	my ($date_in) = @_;
	my $year=substr($date_in, 0, 4);
	my $month=substr($date_in, 5, 2);
	my $day=substr($date_in, 8,2);
	my $hour=substr($date_in, 11, 2);
	my $min=substr($date_in, 14, 2);
	my $sec=substr($date_in, 17, 2);
	my $timestamp=timegm($sec, $min, $hour, $day, $month-1, $year);
	my($sec, $min, $hour, $day, $mon, $year,$wday,$yday,$isdst) = (localtime($timestamp));
	return sprintf("%4d-%02d-%02d %02d:%02d:%02d",$year+1900, ++$mon, $day, $hour, $min, $sec);
}
#====================================================================
sub ET2GMT {
	my ($date_in) = @_;
	my $year=substr($date_in, 0, 4);
	my $month=substr($date_in, 5, 2);
	my $day=substr($date_in, 8,2);
	my $hour=substr($date_in, 11, 2);
	my $min=substr($date_in, 14, 2);
	my $sec=substr($date_in, 17, 2);
	my $timestamp=timelocal($sec, $min, $hour, $day, $month-1, $year);
	my($sec, $min, $hour, $day, $mon, $year,$wday,$yday,$isdst) = (gmtime($timestamp));
	return sprintf("%4d-%02d-%02d %02d:%02d:%02d",$year+1900, ++$mon, $day, $hour, $min, $sec);
}
#=================================================================
sub to_units {
my ($val, $type, $to)=@_;
if (($type eq "ELEV")&&($to eq "metric"))  {$val=$val/3.28084;}
if (($type eq "ELEV")&&($to eq "english")) {$val=$val*3.28084;}
if ((($type eq "ATMP")||($type eq "WTMP"))&&($to eq "metric")) {$val=$val;}
if ((($type eq "ATMP")||($type eq "WTMP"))&&($to eq "english")) {$val=$val*1.8+32 ;}
if (($type eq "PRES")&&($to eq "metric")) {$val=$val*33.7479;}
if (($type eq "PRES")&&($to eq "english")) {$val=$val;}

return $val;
}


#===============================================================
my $match_jul_to_month_non_leap = 
   join '','01'x31,'02'x28,'03'x31,'04'x30,'05'x31,'06'x30,'07'x31,'08'x31,'09'x30,'10'x31,'11'x30,'12'x31;
my $match_jul_to_month_leap = 
   join '','01'x31,'02'x29,'03'x31,'04'x30,'05'x31,'06'x30,'07'x31,'08'x31,'09'x30,'10'x31,'11'x30,'12'x31;
my @cumulative_days_non_leap = (0,31,59,89,120,151,181,212,243,273,304,334);
my @cumulative_days_leap =     (0,31,60,91,121,152,182,213,244,274,305,335);

sub jul_to_month_day {
	my ($year, $julday) = @_;
	my ($month, $day);
	my ($cumulative_days, $day_to_month);
	($year%400 == 0 or ($year%4 == 0 and $year%100 != 0)) 
	?
      ($month = substr($match_jul_to_month_leap,($julday-1)*2,2),
	   $day = $julday - $cumulative_days_leap[$month-1])
   :
      ($month = substr($match_jul_to_month_non_leap,($julday-1)*2,2),
	   $day = $julday - $cumulative_days_non_leap[$month-1])
   ;
	return ($month, $day);
=comment
	if ($year%400 == 0 or ($year%4 == 0 and $year%100 != 0)) { # it be a leap year 
      $month = substr($match_jul_to_month_leap,($julday-1)*2,2);
	   $day = $julday - $cumulative_days_leap[$month-1];
   }
	else {
      $month = substr($match_jul_to_month_non_leap,($julday-1)*2,2);
	   $day = $julday - $cumulative_days_non_leap[$month-1];
   }
	return ($month, $day);
=cut
}

#====================================================================
sub eval_val {
   my ($param_hash, $type, $val)=@_; 
   if (($param_hash->{$type}[1] eq '')||($param_hash->{$type}[0] eq '')) {return 1};
   if (($val<=$param_hash->{$type}[1])&&($val>=$param_hash->{$type}[0])) {return 1;}
	print "problems with: $type, $val\n";
   return 0;
}
#====================================================================
sub validate_and_adjust_data {
   my ($adjuster_hash, $dev, $data_type, $val)=@_; 
	my $key = $dev.$data_type;
	my $good_flag = 0; 
	my $adjusted_val = 0;
   if (not exists $adjuster_hash->{$key}) { $good_flag = 1;}
	else {
		my ($min_val, $max_val, $adjust_val_mult, $adjust_val_offset) = 
				@{$adjuster_hash->{$key}};
   		$adjusted_val = $val * $adjust_val_mult + $adjust_val_offset;
		if ($adjusted_val >= $min_val and $adjusted_val <= $max_val) {$good_flag = 1;}
	}
   return ($good_flag, $adjusted_val);
}
#====================================================================
sub compare_dates {
	# expects dates in format yyyy-mm-dd HH:MM:SS
	my ($dt1, $dt2) = @_;
	my $yr1=substr($dt1, 0, 4);
	my $mon1=substr($dt1, 5, 2);
	my $day1=substr($dt1, 8,2);
	my $hr1=substr($dt1, 11, 2);
	my $min1=substr($dt1, 14, 2);
	my $sec1=substr($dt1, 17, 2);
	my $yr2=substr($dt2, 0, 4);
	my $mon2=substr($dt2, 5, 2);
	my $day2=substr($dt2, 8,2);
	my $hr2=substr($dt2, 11, 2);
	my $min2=substr($dt2, 14, 2);
	my $sec2=substr($dt2, 17, 2);
	my $ts1=timelocal($sec1, $min1, $hr1, $day1, $mon1-1, $yr1);
	my $ts2=timelocal($sec2, $min2, $hr2, $day2, $mon2-1, $yr2);
	return $ts1 - $ts2;

}
#====================================================================
sub inc_date_by_seconds {
	# expects dates in format yyyy-mm-dd HH:MM:SS$, adds seconds and returns date
	my ($dt, $interval) = @_;
	my $yr=substr($dt, 0, 4);
	my $mon=substr($dt, 5, 2);
	my $day=substr($dt, 8,2);
	my $hr=substr($dt, 11, 2);
	my $min=substr($dt, 14, 2);
	my $sec=substr($dt, 17, 2);
	my ($wday, $yday, $isdst);
	my $ts=timegm($sec, $min, $hr, $day, $mon-1, $yr);
	my $diff = $ts + $interval;
	($sec, $min, $hr, $day, $mon, $yr,$wday,$yday,$isdst) = (gmtime($diff));
	return sprintf("%4d-%02d-%02d %02d:%02d:%02d",$yr+1900, ++$mon, $day, $hr, $min, $sec);

}
sub read_entire_file {
	my ($file_in) = @_;
	my $data;
	my $length = -s $file_in;
	open DATA, $file_in or die "can't open file $file_in\n";
	read DATA, $data, $length;
	close DATA;
	return $data;
}
sub convert_date_to_seconds {
	# expects dates in format yyyy-mm-dd HH:MM:SS$, returns seconds since
	my ($dt) = @_;
	my $yr=substr($dt, 0, 4);
	my $mon=substr($dt, 5, 2);
	my $day=substr($dt, 8,2);
	my $hr=substr($dt, 11, 2);
	my $min=substr($dt, 14, 2);
	my $sec=substr($dt, 17, 2);
	my ($wday, $yday, $isdst);
	return timegm($sec, $min, $hr, $day, $mon-1, $yr);

}
sub convert_seconds_to_date {
	# expects dates in format yyyy-mm-dd HH:MM:SS$, returns seconds since
	my ($seconds) = @_;
	my ($sec, $min, $hr, $day, $mon, $yr,$wday,$yday,$isdst);
	($sec, $min, $hr, $day, $mon, $yr,$wday,$yday,$isdst) = (gmtime($seconds));
	return sprintf("%4d-%02d-%02d %02d:%02d:%02d",$yr+1900, ++$mon, $day, $hr, $min, $sec);

}
1;
