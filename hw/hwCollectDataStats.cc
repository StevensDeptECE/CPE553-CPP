#include <iostream>
#include <unordered_map>
using namespace std;

class NamedDataStats {
public:
	void data(const char name[], const char field[]);

	friend ostream& operator <<(ostream& s, const NamedDataStats& named) {
		return s << "todo!";
	}
};


int main() {
	// integers range from -2**31 to 2**31-1
	// no decimal points
	const char* integerExample[] = {
		"123", "-123", "543219876", "-1239876542"
	};

	// unsigned integers go up to 2**32, about 4.2 billion
	// no negatives
	const char* unsignedIntegerExample[] = {
		"123", "543219876", "1239876542", "2345678901", "4100000000"
	};

	const char* signedLongExample[] = {
		"123", "-123", "543219876", "-1239876542", "123456789012345678",
		"-123456789012345678"
	};

	const char* unsignedLongExample[] = {
		"123", "543219876", "1239876542", "2345678901", "4100000000",
		"1234567890123", "123456789012345678"
	};

	const char* fixedPrecisionExample[] = {
		"1.23", "-1.23", "1.245", "-1.2355", "0.", "-9.87654"
		"5432198", "-9876542",
	};

	const char* singlePrecisionExample[] = {
		"123", "-123", "1.2", "-1.23", "0.", ".01", "6.022e+23",
		"5432198", "-9876542", "5.67e-11"
	};

	const char* doublePrecisionExample[] = {
		"123", "-123", "1.2", "-1.23", "0.", ".01", "6.022e+23",
		"5432198", "-9876542", "5.67e-11",
		"1.23456789012345", "1.2345678", "-1.23"
	};

	const char* symbolExample[] = {
		"abc", "a123", "ABC",		"ABC123", "CamelCaseIsGreat", "snake_case_slithers5",
		"__LINE__",	"_WTF", "_intrinsics"
	};

	const char* stringExample[] = {
		"123", "-123", "1.24",		"5432198", "-9876542", "5.67e-11",
		"1.23456789012345",
		"abc", "this is a test", "What is the air speed of an unladen swallow?",
		"\\frac{n}{d}", "3@a-c&&^32"
	};

	/*
		This homework is to try to automatically infer the data type of
		a set of strings.  To make the homework easier, this test is
		hardcoded, but you can imagine reading in a data file and trying
		to discover the type of each value.  Consider, for example, the
		file simple.xml in which there are different kinds of values.

		In the hierarchy, anything that has a leading - cannot be unsigned
		Anything with more then 10 digits cannot be 32 bit but you must
		check the actual number to determine whether int32 or uint32 has
		been exceeded. For example, the number 4300000000 is beyond the
		range of a uint32_t

		Anything containing a . cannot be an integral type, but if it
		contains illegal letters than it may be a string.  Strings can be
		any sequence of letters, but if there are only letters digits and
		underscores, with a leading letter or underscore, then symbol is
		preferred

	 */
	
	
	NamedDataStats nd;
	for (auto x : integerExample)
		nd.data("a", x);

	for (auto x : unsignedIntegerExample)
		nd.data("b", x);

	for (auto x : signedLongExample)
		nd.data("c", x);

	for (auto x : unsignedLongExample)
		nd.data("d", x);

	for (auto x : singlePrecisionExample)
		nd.data("e", x);

	for (auto x : doublePrecisionExample)
		nd.data("f", x);

	for (auto x : stringExample)
		nd.data("g", x);

	cout << nd; // should print out the following:
	/*
    a is int32_t
    b is uint32_t
    c is int64_t
    d is uint64_t
    e is float
    f is double
    g is string
	*/

}
