#include "Shape.hh"
#include <iostream>
class Pentagon : public Shape{
private:
	double rad;
public:
	Pentagon(double x, double y, double rad) : Shape(x,y), rad(rad){}
	double area() const override {
        return  perimeter()*rad/2; //(perimeter*rad)/2 
    }

    double perimeter() const override {
		return 10 * rad * sin(36); //5*side length = 2rsin(180/n) 
	}

    void print(std::ostream& s) const {
		s << "Perimeter: " << perimeter() << ", Area: " << area();
	}
};