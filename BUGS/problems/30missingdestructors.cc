#include <iostream>
#include <cstring>
using namespace std;

class A {
public:
	A() { cout << "A born" << endl; }
	~A() { cout << "A dying" << endl; }
};

int main() {
	A* p = new A[10]; // create 10 A objects
	delete p; // delete them
}
