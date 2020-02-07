#include <iostream>
#include <string>
using namespace std;

int main() {
	char s[] = "abcd"; // \0  (control ^@)  ASCII NUL
	for (int i = 0; s[i] != '\0'; i++)
	
	string a = "abc";
	cout << a;
	a += a; // abcabc
	cout << a.size();
	cout << a.substr(2, 2) << "\n"; // ca

	cout << a.substr(2) << "\n"; // cabc
	cout << a.substr() << "\n"; // abcabc
	string b; // this is a test
 	cin >> b;
 	cout << "b=" << b << "\n";
 	getline(cin,  b); // read in everything until the new line
	cout << b << "\n";
}
