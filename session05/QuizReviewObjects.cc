#include <iostream>
using namespace std;

class A {
private:
  int x;	
public:
	A() : x(3) { cout << "A"; }
	A(int x) : x(x) { cout << "b"; }
	void f() const { cout << "c"; }
	~A() { cout << "D"; }
};

void f() {
	A a1(2);
}

int main() {
	 f();
	 A a2;                  //output: bDAD 
}
