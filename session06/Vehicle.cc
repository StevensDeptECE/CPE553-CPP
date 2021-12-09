#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
	int speed;
public:
	Vehicle(int s) : speed(s) {}
	virtual void payToll() = 0;
};

class Car : public Vehicle {
private:
	string color;
public:
	Car(int s, const string& color) : Vehicle(s), color(color) {}
	void payToll() override { cout << "pay $15"; }
};

class Sportscar : public Car {
private:
	double hp;
public:
	Sportscar(int s, const string& color, double hp) : Car(s, color), hp(hp) {}
  void payToll() override { cout << "pay $25"; }
};

int main() {
	//	Vehicle v(55);
	Car c(55, "red");
	Sportscar s(90, "red", 450);
	//	v.payToll();
	c.payToll();
	s.payToll();

	Vehicle* v  = &c1;
	v->payToll();   //   (*v).payToll()
	v = &s;
	v->payToll();
}
