#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
// don't use #define, it's confusing: #define PI 3.1415926?"5358979


const double PI = 3.14159265358979;

class Shape { // abstract class
private:
	double x,y;
public:
	Shape(double x, double y) : x(x), y(y) {}
	// pure virtual function
	double getX() const { return x; }
	double getY() const { return y; }
	virtual	double area() const = 0; // shape is abstract (you cannot make one)
	// cannot instantiate an object
};

class Circle : public Shape { // is a Shape (is a kind of Shape)
private:
	double r;
public:
	Circle(double x, double y, double r) : Shape(x,y), r(r) {}
	double area() const { return PI * r*r; }
};

class Rect : public Shape {
private:
	double w,h;
public:
	Rect(double x, double y, double w, double h) : Shape(x,y), w(w), h(h) {}
	double area() const { return w*h; }
};

class Line : public Shape {
private:
	double x2, y2;
public:
	Line(double x1, double y1, double x2, double y2) : Shape(x1,y1), x2(x2), y2(y2)
	{}

	double area() const { return 0; }
};

int main() {
	const Circle c1(40.0,50.0, 25.0);
	cout << c1.area() << '\n';
	const Rect r1(20,30, 50,20);
	cout << r1.area() << '\n';
	const Line line(0,0, 100,100);
	cout << line.area() << '\n';
	vector<const Shape*> shapes;
	shapes.push_back(&c1);
	shapes.push_back(&r1);
	shapes.push_back(&line);

	for (int i = 0; i < shapes.size(); ++i)
		cout << shapes[i]->area();
	
}
