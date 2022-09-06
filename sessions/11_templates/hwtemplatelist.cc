#include <iostream>
using namespace std;

GrowArray<string> buildList(const string s, int n) {
	GrowArray<string> temp(n);
	for (int i = 0; i < n; i++) {
	  temp.addEnd(s);
	  s += s;
	}
	return temp; // test move constructor
}

int main() {
	GrowArray<int> a(100);
	for (int i = 0; i < 1000000; i++)
		a.addEnd(i);
	for (int i = 0; i < 999990; i++)
		a.removeEnd();
	// should have 0 1 2 3 4 5 6 7 8 9		 
	cout << a << '\n';
	
	List<string> b;
	b.add("hello");
	string s[] = { "test", "this", "now" };
	
	for (int i = 0; i < sizeof(s)/sizeof(string); i++)
		b.add(s[i]);
	b.removeEnd();
	cout << b << '\n';

	GrowArray<string> c = b; // test copy constructor
	c.removeEnd();
	c = b; // test operator =
}
