#include <time.h>

class JulianDate {
private:
	static int EPOCH;
	//	int mon, day, year, hour, min, second;
	// this representation would make difference VERY UGLY
	// diff between Jan. 1 2001 12:03:04  and Feb 26 2028 11:19:02
	double jday; // number of days since epoch

};

/*
	how many days in a year? 365
	leap year: if year MOD 4 == 0 LEAP EXCEPT
	           if year MOD 100 == 0 NOT LEAP YEAR Except
						 if year MOD 400 == 0 LEAP

Leap years:
 NO 1900 
 YES 1904
 YES 1908
 YES 2000
 NO 2100
 YES 2400

    days since EPOCH = 365 * (year - 2000) + years/4 - ....

2018 - 2000 = 18

seconds in a day = 24*60*60 = 86400

hh:mm:ss     

00:00:00  0.0
12:00:00  0.5

http://aa.usno.navy.mil/faq/docs/JD_Formula.php
http://www.math.harvard.edu/~knill/3dprinter/exhibits/bc/Meeus1988.pdf













 */



int JulianDate::EPOCH = 2000; // Jan.1 2000, 00:00:00 = 0

int main() {
	JulianDate newyear(2018, 1, 1, 0,0,0);
	JulianDate valentine(2018, 2, 14, 12,0,0);
	JulianDate today; // get it from the system time: time(nullptr)
	                  // localtime

	double days = valentine - newyear;
	JulianDate due = today + 7;
	cout << due << '\n';

	cout << "\nyear: " << newyear.getYear()
			 << "\nmonth: " << newyear.getMonth()
			 << "\nday: " << newyear.getDay()
			 << "\nhour: " << newyear.getHour()
			 << "\nmin: " << newyear.getMin()
			 << "\nsec: " << newyear.getSec() << '\n';
}

		
