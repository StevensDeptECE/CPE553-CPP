#pragma once
#include "Vehicle.hh"

class Car : public Vehicle {
private:
	std::string color;
public:
	Car(int speed, const std::string& color) : Vehicle(speed), color(color) {}
	double payToll() const {
		return 15;
	}
};
