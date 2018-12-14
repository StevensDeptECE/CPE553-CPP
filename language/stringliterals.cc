#include <iostream>
#include <string>

using namespace std;

int main() {
	const char big[] = "this is a very long string\n"
		"long strings can be broken up\n"
		"the compiler automatically concatenates them\n";

	// the above is much more efficient than:

	string big2 = "this is a very long string\n";
	big2 += "long strings can be broken up\n";
	big2 += "the compiler automatically concatenates them\n";

	/*
		In C++11 Raw strings offer a nice way to store really big strings
		as well as strings containing backslashes and other characters that are
		not easy to write because they must be doubled up.
	*/
	
	const char s[] = R"foo(
================================================================

Oooh! look, it's formatted in the string just like it should be
printed.

================================================================
look, you can do regex too!
([a-zA-Z][a-zA-Z0-9]*)\s+=\d+
)foo";

}
