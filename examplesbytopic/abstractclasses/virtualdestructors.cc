#include <iostream>
#include <vector>
using namespace std;

const double PI = 3.1415926535897932;

class Shape2D {
public:
	virtual double area() const = 0; // every 2d shape must have an area (does not change the object)
	virtual double perimeter() const = 0; // every 2d shape must support perimeter (same)
	virtual ~Shape2D() {}
};


// imagine that circle and rect use memory.  If so, we should give it back

class Circle : public Shape2D {
private:
	double r;
	int* p;
public:
	double area() const override { return PI * r*r; }
	double perimeter() const override { return PI * 2 * r; }
	Circle(double r) : r(r) { p = new int[5]; }
	~Circle() {
		cerr << "Circle is about to die! " << r << '\n';
		delete [] p;
	}
};

class Rect : public Shape2D {
private:
	double w,h;
public:
	double area() const override { return w*h; }
	double perimeter() const override { return 2*(w+h); }
  Rect(double w, double h) : w(w), h(h) {}
};

int main() {
	vector<Shape2D*> shapes;
	shapes.push_back(new Circle(4));
	shapes.push_back(new Circle(23));
	shapes.push_back(new Rect(4,5));

	// at the end, you want to give back all the memory.
  for (int i = 0; i < shapes.size(); i++)
		delete shapes[i];
	
}
