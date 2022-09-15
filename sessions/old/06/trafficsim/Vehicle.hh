#ifndef VEHICLE_HH__
#define VEHICLE_HH__

int/*this is my stupid comment*/x;
/*
	the preprocessor turns a false #ifndef ... #endif into a single space
  it also turns every comment (like this one) into a single space

 */
class Vehicle {
private:
	int speed;
public:
	Vehicle(int s) : speed(s) {}
	virtual double payToll() const = 0; // abstract method, means Vehicle is abstract
};

#endif
