#include <iostream>
using namespace std;

class Engine {
private:
  int hp;
public:
  Engine(int hp) : hp(hp) {}
};

class Wheel {
private:
	int pressure;
public:
	Wheel(int p) : pressure(p) {}
};

class Vehicle {
private:
  int speed;
public:
  Vehicle(int speed) : speed(speed) {}
};

// Inheritance
// 1. Car IS_A Vehicle
// 2. A car is exactly one vehicle 1:1
// 3. A car will always be a vehicle
class Car : public Vehicle {
private:
  Engine e;
  Wheel w1,w2,w3,w4;
public:
  Car(int speed, int hp, int press) :
		Vehicle(speed), e(hp), w1(press), w2(press), w3(press), w4(press)
  {}
};

int main() {
  // create a car with speed =55 with an engine, 4 wheels each with 30 psi
  Car c(55, 480, 30);
	cout << sizeof(c) << '\n';
}
