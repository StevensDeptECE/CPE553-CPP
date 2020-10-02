#include <iostream>
using namespace std;

class A {
	int a; //4
	char b;//1
	int c; //4
	uint64_t d; // 8
	bool e; // 1
	double f; // 8
};

class A2 {
	uint64_t d; // 8
	double f; // 8
	int a; //4
	int c; //4
	char b;//1
	bool e; // 1

};

int main() {
	A a1;
	cout << sizeof(A) << '\n'; // 26 --> 40
	cout << sizeof(A2) << '\n'; // 26? --> 32
	A2 a[10];
}
