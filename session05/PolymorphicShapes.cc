#include <iostream>
using namespace std;
const double PI = 3.14159265358979;

class Shape {
public:
	virtual double area() const = 0;
};

class Circle : public Shape {
private:
	double radius;
public:
	Circle(double radius) : radius(radius) {}

	double area() const  { return PI * radius*radius; }
};

class Rect : public Shape {
private:
	double w,h;
public:
	Rect(double w, double h) : w(w), h(h) {}
	double area() const { return w*h; }
};

int main() {
	Rect r(3,4);	
	cout << r.area() << '\n';

	Circle c(4);
	cout << c.area() << '\n';

	// this is polymorphism: calling different functions at runtime depending on the object
	Shape* s = &r;
	cout << s->area() << '\n';
	s = &c;
	cout << s->area() << '\n';
	//	cout << (*s). area() << '\n';
}
