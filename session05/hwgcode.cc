#include <iostream>
#include <vector>

using namespace std;

class Shape { // abstract class
	//protected:
	//	double x,y;
public:
	// pure virtual function
	virtual void print(ostream& s) = 0;	 // We don't know how to print a shape
};

class Circle {
private:
	double x,y;
	double radius;
public:
	void print(ostream& s) {
	}
};

class Square : public Shape { 
private:
	double x,y;
  double side;
public:
	Square(double x, double y, double side) : x(x), y(y), side(side) {}
	void print(ostream& s) {
		double e = 0;
		double f = 0.5;
		cout << "g0 x" << x << " y" << y << '\n';
		e += side*f;
		cout << "g1 x " << (x + side) << " y" << (y + 0) << " e" << e << '\n';
		e += side*f;
		cout << "g1 x " << (x + side) << " y" << (y + side) << " e" << e << '\n';
		e += side*f;
		cout << "g1 x " << x << " y" << (y + side) << " e" << e << '\n';
		e += side*f;
		cout << "g1 x " << x << " y" << y << " e" << e << '\n';
	}
};

/*
	instructions: 
1. write to a file, not to cout
2. implement circle (use a variable to control the number of facets?)
3. Optional: Can you move x,y into Shape to save effort?

 */
int main() {
	ofstream f("test.gc");
	vector<Shape*> shapes;
	//shapes.push_back(new Circle(0,0, 3 ));
	shapes.push_back(new Square(2,0,2 ));
	

	for (auto s : shapes)
		s->print(f);
}
