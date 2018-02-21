#include <iostream>
using namespace std;

class A {
private:
	const int x;
public:
	A(int x) { this->x = x; }
}
	
int main() {
	A a1(1);
}
