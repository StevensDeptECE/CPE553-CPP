#include <iostream>
#include <string>
using namespace std;

int f(string s) {
	return s[2];
}
int main() {
	string s = "abc";
	for (int i = 0; i < 20; i++)
		s += s;
	int sum = 0;
	for (int i = 0; i < 20000; i++)
		sum += f(s);
	cout << sum << '\n';
}
