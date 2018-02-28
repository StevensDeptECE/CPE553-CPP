#include <iostream>

#include "Car.hh"
#include "Bus.hh"
#include "Truck.hh"

using namespace std;

int main() {
	const Vehicle* list[10];
	const Car c(55, "red");
	cout << c.payToll();
	Truck t(90, 5, 18000);
  Bus b(45, 13);
	
	list[0] = &c;
	list[1] = &t;
	list[2] = &b;
	//  t.setWeight(10000); // change t if you want, it is NOT const
	//	list[1]->setSpeed(100); illegal: list[1] is const!
	for (int i = 0; i < 3; i++) {
		cout << (*list[i]).payToll() << '\n';
	}

		for (int i = 0; i < 3; i++) {
		cout << list[i]->payToll() << '\n';
	}

	
	

}
