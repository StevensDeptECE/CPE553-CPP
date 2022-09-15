#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	int julday; // number of days since epoch=Jan.1 2000
  const static int daysPerMonth[12];
  const static int cumulativeDaysUpToMonth[12];
  const static string monthNames[12];
	Date(int julday) : julday(julday) {}
public:
	Date(int year, int mon, int day) {
		int dy = year - 2000; // daysperyear = 365.2425
		int days = 365*dy + dy / 4 - dy / 100 + dy / 400;
		days += cumulativeDaysUpToMonth[mon-1];
		julday = days + 0; //TODO: something for days in this month

		// if mon >= 3
		// rule for isLEapyear:  (y % 4 == 0 && y % 100 != 0) || y % 400 == 0
		//		if isLeap() julday++;
	}
	int year() const {
		return 0; // TODO:
	}
	int mon() const {
		return 0; // TODO:
	}
	int day() const {
		return 0; // TODO:
	}
	
	friend	Date operator +(Date d, int days) {
    return Date(d.julday + days);
	}
	friend	Date operator -(Date d, int days) {
    return Date(d.julday - days);
	}

	friend int operator -(Date d1, Date d2) {
		return d1.julday - d2.julday;
	}
	friend ostream& operator <<(ostream& s, Date d) {
		return s << d.year() << "-" << Date::monthNames[d.mon()] << "-" << d.day();
	}
};

const int Date::daysPerMonth[12] =
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int Date::cumulativeDaysUpToMonth[12] =
	{0, 31, 59, //...31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};

const string Date::monthNames[12] =
	{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int main() {

	Date d1(2019, 9, 20);
	Date d2 = d1 + 3; // 3 days from today
	//	Date d3 = d1 + d2; // makes NO SENSE
	//	Date d3 = d2 * 2; // NO
	Date d3(2020, 3, 15);
	int days = d3 - d1;

	cout << d1; // Sep. 20, 2019
}	
