#include <iostream>
#include <cmath>
using namespace std;

class Shape { // base class
public:
	virtual double area() const = 0; // pure virtual function
};

class Circle : public Shape { // A circle is a shape (derived class)
private:
  double r;
public:
	Circle(double r) : r(r) {}
	double area() const override {
		return M_PI * r * r;
	}
};

class Rect : public Shape {
private:
	double w, h;
public:
	Rect(double w, double h) : w(w), h(h) {}
	double area() const override {
		return w * h;
	}
};

class Vec3d {
public:
	double x,y,z;
	Vec3d(double x, double y, double z) : x(x), y(y), z(z) {}
};

int main() {
	const Circle c(2.5);
	cout << c.area() << '\n';

	
	Shape* list[] = {
									 new Circle(10.0),
									 new Rect(5.0, 4.0),
									 new Circle(4.0),
	};
	//	for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
	for (int i = 0; i < sizeof(list) / sizeof(Shape*); i++)
		cout << list[i]->area() << '\n';

	for (auto s : list) {
		cout << s->area() << '\n';
	}
}
