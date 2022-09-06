#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
//#include <numbers>

class Shape {
private:

public:
	virtual double area() const = 0 ; // pure virtual
};


class Circle : public Shape {
private:
	double x, y, r;
public:
  Circle(double xi, double y, double r) : r(r) {
		x = xi;
		this->y = y;
	}
	double area() const override {
		return M_PI * r * r;
	}
};

class Triangle : public Shape {
private:
	double x1, y1, x2, y2, x3, y3;
public:
  Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
		: x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}
	double area() const override {
		double T = __________; // 
		return T;
	}
};
#include <vector>
using namespace std;

int main() {
  vector<Shape*> shapes;
  shapes.push_back(new Circle(10.0, 20.0, 5.0)); // x,y,radius
  shapes.push_back(new Triangle(0.0, 0.0, 30.0, 1.0, 15.5, 13.2)); // x1,y1,x2,y2,x3,y3

	//each shape must have a method area() returning the area of that shape
  double total_area = 0;
  for (auto s: shapes) // complete this loop to add all the areas of the shapes.
    total_area += s->area();

  // write the same loop using for (int i = 0; …)
  for (int i = 0; i < shapes.size(); i++)
		total_area += shapes[i]->area();
}
