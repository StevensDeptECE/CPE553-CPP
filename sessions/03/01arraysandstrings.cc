#include <string>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int a;
	int b[] = {1,2,3}; // b[0], b[1], b[2]
	int c[4]; // random garbage (if zero, we are just LUCKY!!)
	int d[5] = {3, 2, 1}; // last two are zero
	int e[100] = {0}; // first one is zero, and so are all the rest
	for (int i = 0; i < 3; i++) // should not hardcode 3, but ok...
		cout << b[i]; // prints 123
	for (int i = 4; i >= 0; i--)
		cout << d[i]; // 00123
	const char s[] = "abcd"; // s[0] = 'a' s[1] = 'b' s[2] = 'c' s[3] = 'd' s[4] = '\0'  NUL ^@
	
	cout << s << '\n';
	cout << sizeof(s) << '\n'; // size of s = 5
	cout << sizeof(b) << '\n'; // size of b = 3*4 = 12
	cout << strlen(s) << '\n'; // string length of s = 4

	string s2 = "abc";
	string s3 = s2 + s2; // "abcabc"
	cout << s2.substr(1, 2) << '\n';
	cout << s3.length() << "\n";
}
