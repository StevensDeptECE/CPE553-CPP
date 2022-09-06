#include <iostream>
using namespace std;

class Airplane {
public:
	void fly() {} // airplanes can fly
};

class PassengerPlane : public Airplane {
public:
	void serveCoffee() {} // passenger planes can fly,
	//but they can also serve cofee, but evidently only bad food
};

class FighterPlane : public Airplane {
public:
	void shoot() {} // military planes can shoot things
};

int main() {
	int a = 3;
	//double* pb = &a; // illegal
	double* pb = (double*)&a; // legal, but stupid
	cout << *pb << '\n'; // print out the value, whatever it might be....

	const int* b = &a; // it's fine to get more restrictive
	int*pi = const_cast<int*>(b); // ok

	Airplane* a = new PassengerPlane(); // ok for a base class to point to derived
	PassengerPlane* p = dynamic_cast<PassengerPlane*>(a); // we know it's a passenger plane!
	// p will be null if we try to cast one that is not

	a = new FighterPlane();
	p = dynamic_cast<PassengerPlane*>(a); // not correct, so p will be null
	
}
	
