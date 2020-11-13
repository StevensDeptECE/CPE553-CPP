#include <iostream>
using namespace std;
#include "f.hh"

void f(); // function prototype (same)

float x=1.5f; //globals are binary zero

int main() {
	cout << x << '\n';
	f();
}
