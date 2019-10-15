#include <iostream>
using namespace std;

/*
  421
	000 = 0
	001 = 1
	010 = 2
	011 = 3
	100 = 4
	101 = 5
	110 = 6
	111 = 7
    1
=====
 1000

  -21
	000 = 0
	001 = 1
	010 = 2
	011 = 3
	100 = -4
	101 = -3
	110 = -2
	111 = -1


 */

int main() {
	cout << 7 * 24 * 60 * 60 << '\n';
	cout << 365 * 24 * 60 * 60 << '\n';
	cout << 69 * 365 * 24 * 60 * 60 << '\n';
	int age = 138;
	cout << age * 365 * 24 * 60 * 60 << '\n';
	//type promotion: when two types are different, promote the smaller
	// 3 + 2L
	cout << sizeof(365LL) << '\n';
  uint64_t secondsInAge = age * 365LL * 24 * 60 * 60;
	cout << secondsInAge << '\n';
}
