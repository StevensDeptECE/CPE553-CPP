#include <iostream>
using namespace std;

extern void f(); //declaration that function f exists
void f(); // function prototype (same)

int main() {
	f();
}
