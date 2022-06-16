#include <iostream>
using namespace std;


void f(int x) { cout << "int"; }
//void f(float x) { cout << "float"; }
void f(double x) { cout << "double"; }
void f(const char* s) { cout << s; }
int main() {
	f(3);
	//	f(2L); error, ambiguous
	f(float(2L));
	f(1.5);
	f(1.2f);
}
