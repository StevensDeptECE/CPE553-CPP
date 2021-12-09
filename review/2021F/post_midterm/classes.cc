/*
	vector<const Shape*> shapes;
  // create a sphere with radius =2
  shapes.push_back(new Sphere(2.0));
  // create a cylinder with radius = 3, height = 2.5
  shapes.push_back(new Cylinder(3.0, 2.5));
 */
#include <cmath>
#include <numbers>

class Shape {
public:
  virtual double area() const = 0; // pure virtual
  virtual double volume() const = 0;
};

class ParallelPiped : public Shape {
private:
	double L, W, H;
public:
	ParallelPiped(double L, double W, double H) : L(L), W(W), H(H) {}
  double area() const override {
		return 2*(L*W + W*H + L*W);
	}
		
  double volume() const override {
		return L*W*H;
	}
};

class CircularShape : public Shape {
public:
	double r;
	CircularShape(double r) : r(r) {}
};


class Sphere : public CircularShape {

public:
	Sphere(double r) : r(r) { } 
	double area() const override {
		return 4*M_PI*r*r;
	}
	double volume() const override {
		return (4.0/3)*M_PI*r*r*r;
	}
};

class Cylinder : public CircularShape {
private:
	double h;
public:
	Cylinder(double r, double h)
};



int main() {
	Shape* s; // s is a pointer to Shape
	//  Shape shape; // cannot instantiate Shape because it is an ABSTRACT CLASS
  Sphere sphere(2.0); // error cannot instantiate Sphere because abstract member area is not overridden
  vector<const Shape*> shapes;
	shapes.push_back(new Sphere(2.0));
	shapes.push_back(new Cylinder(3.0, 4.5));
	shapes.push_back(new ParallelPiped(4.0, 5.0, 9.0));

	for (int i = 0; i < shapes.size(); i++)
		cout << shapes[i]->area();

	for (auto s : shapes) {
		cout << s->area();
	}

	for (const auto& s : shapes) {
		cout << s->area();
	}

	/*
		list <-- [sphere, cylinder, parallelpiped]

    list <-- cylinder, cylinder, cylinder
	 */
	// not on midterm
	for (auto& s : shapes) {
		s = new Cylinder(2.0, 4.0);
		//s->r = 99;
		cout << s->area();
	}

}
	
