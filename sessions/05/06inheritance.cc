#include <iostream>
#include <string>
using namespace std;

// parent,  C++ = base class
class Car {
private:
	string color;
	int speed;
public:
	Car(const string& c, int s) : color(c), speed(s) {}
	int payToll() {
		return 15; }
};

// child, c++ = derived class
class SportsCar : public Car { // IS_A IS A KIND OF ....
private:
	double horsePower;
public:
	SportsCar(const string& c, int s, double hp) : Car(c, s), horsePower(hp) {}
	int payToll() { return 25; }
};

/*

this -->   string color        p p p p p p p p
                               s s s s c c c c
           int    speed        s s s s - - - - 
           double horsepower   h h h h h h h h
*/


int main() {
	Car c1("red", 55);
	SportsCar s("red", 180, 280.0); // use inheritance
	cout << c1.payToll();
	cout << s.payToll();

	int x;
	// CRASH!	Car* cp = (Car*)&x;

	Car* cp = &c1;
	cout << (*cp).payToll() << '\n';
	cout << cp->payToll() << '\n';

	/*
		cannot point to incompatible types
		int a = 2;
		double d = 3.5;
		int* p = &a;
		p = &d;
	*/
	
	cp = &s;
	cp->payToll(); // $15


	if (you are pointing at a car)
		call Car::payToll();
	else if (you are pointing at a sportscar)
		call SportsCar::payToll();
	

	
}
