#include <iostream>
using namespace std;


int main() {
	GrowArray<int> a(100);
	for (int i = 0; i < 1000000; i++)
		a.add(i);
	for (int i = 0; i < 999990; i++)
		a.removeEnd();
	// should have 0 1 2 3 4 5 6 7 8 9		 
	cout << a << '\n';
	
	List<string> b;
	b.add("hello");
	string s[] = { "test", "this", "now" };
	
	for (int i = 0; i < sizeof(s)/sizeof(string); i++)
		b.add(s[i]);
	cout << b << '\n';

}
