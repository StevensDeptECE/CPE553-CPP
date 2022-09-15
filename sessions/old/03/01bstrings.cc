#include <string>
#include <iostream>
using namespace std;

int main() {
	char c = 'x'; // one byte  (wchar_t is 4 bytes)
	char s[80] = "abc"; // a b c \0   NUL   ^@  ctrl-shift-2
	//	char s2[3] = "abc"; // you just went 1 character beyond....

	string s3 = "abc";
	cout << s3;
	for (int i = 0; i < s3.length(); i++)
		cout << s3[i];

	// this is deadly
	for (int i = 0; i < 10000; i++)
		cout << s3[i];
	
}
