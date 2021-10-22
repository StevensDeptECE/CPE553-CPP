#include <iostream>
#include <cmath>
#include <vector>
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

int main() {
	vector<Shape*> shapes;
	shapes.push_back(new Circle(10.0));
	shapes.push_back(new Rect(5.0, 4.0));
	shapes.push_back(new Circle(4.0));
	for (int i = 0; i < list.size(); i++)
		cout << shapes[i]->area() << '\n';

	for (vector<Shape*>::const_iterator i = shapes.begin(); i != shapes.end(); ++i)
		cout << (*i)->area() << '\n';
   	
	for (auto s : list) {
		cout << s->area() << '\n';
	}

	vector<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(i);

	for (int i = 0; i < a.size(); i++)
		cout << a[i];

	for (auto x : a) {
		cout << x;
	}
	for (auto& x : a) {
		x *= 2; // double every element in the list
	}

	for (vector<int>::iterator i = a.begin(); i != a.end(); ++i)
		*i *= 2;
}
