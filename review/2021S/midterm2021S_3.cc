#include <bits/stdc++.h>
using namespace std;

const double pi = 3.141592653589793;

class Shape3D {
public:
	virtual double surfaceArea() const = 0;
};

class Sphere : public Shape3D {
private:
	double r;
public:
	double surfaceArea() const override {
		return 4 * pi * r*r;
	}
};

class Cube : public Shape3D {
private:
	double s;
public:
	double surfaceArea() const override {
		return 6*s*s;
	}
};

class ParallelPiped : public Shape3D {
private:
	double L, W, H;
public:
};
main() {
	//	vector<Shape3D> shapes; // abstract class, can't make a Shape3D!
	vector<Shape3D*> shapes;

	shapes.push_back(new Cube(2.5));
	shapes.push_back(new Sphere(2.22));
	shapes.push_back(new ParallelPiped(3, 4, 6.2));
#if 0
	for (int i = 0; i < shapes.size(); i++)
		delete shapes[i];
#endif

	for (auto s : shapes) {
		delete s;
	}

	int x; // x is an auto variable (on the stack)
	for (vector<Shape3d*>::iterator i = shapes.begin(); i != shapes.end(); ++i)
		delete *i;
}
	
