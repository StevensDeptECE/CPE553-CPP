#include <iostream>
using namespace std;

// parent,  C++ = base class
class Car {
private:
	string color;
	int speed;
public:
	Car(const string& c, int s) : color(c), speed(s) {}
	virtual int payToll() {
		return 15; }
	virtual void noise() {
		cout << "rumble";
	}
};

// child, c++ = derived class
class SportsCar : public Car { // IS_A IS A KIND OF ....
private:
	double horsePower;
public:
	SportsCar(const string& c, int s, double hp) : Car(c, s), horsePower(hp) {}
	int payToll() { return 25; }
	void noise() {
		cout << "vroom!";
	}
};

/*

this -->   pointer to VFT      p p p p p p p p
           string color        p p p p p p p p
                               s s s s c c c c
           int    speed        s s s s - - - - 
           double horsepower   h h h h h h h h
*/

#if 0
class A {
private:
	char x;                // x - - - y y y y
	int y;
	char z;                // z - - - - - - -
	double a;              // a a a a a a a a
	char w;                // w - - - - - - -
};

class A {
private:
	char x, z, w;         // x z w - y y y y
	int y;
	double a;             // a a a a a a a a
A a1[3];
#endif

int main() {
	Car c1("red", 55);
	SportsCar s("red", 180, 280.0); // use inheritance
	cout << c1.payToll();
	cout << s.payToll();
	c1.noise();
	s.noise();
	int x;
	// CRASH!	Car* cp = (Car*)&x;

	Car* cp = &c1;
	cout << (*cp).payToll() << '\n';
	cout << cp->payToll() << '\n';
	cp->noise();
	
	cp = &s;
	cout << cp->payToll(); // $25
  cp->noise();
	

	
}
