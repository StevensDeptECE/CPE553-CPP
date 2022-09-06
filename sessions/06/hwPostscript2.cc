#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
	suggestion:
for this assignment:

// what makes an abstract class???
class Shape {
private:
double x,y;
public:
  Shape(double x, double y) : x(x), y(y) {}
  virtual void draw(ostream& s)  = 0;
	virtual ~Shape() {}
};

class Circle : public Shape {
private:
 void draw(ostream& s) override {...}
// ~Circle() {}
};

 */

class Drawing {
private:
	ofstream f;
	vector<Shape*>  shapes;
public:
	Drawing(string filename) : f(filename.c_str()), shapes() {
	}
	~Drawing() { // write destructor
    //delete each individual pointer in the shapes list!
	}
	void add( Shape* s ) {
    shapes.push_back(s);
	}

	void draw() const {
		for (int i = 0; i < numShapes; i++)
			shapes[i]->draw(f);
	}
};

void printIt(const Drawing& d) {
	d.draw();
}

int main() {
	Drawing d("test2.ps");
	d.setrgb(1,0,0); // set drawing color to be bright red:  1 0 0 setrgbcolor
	//d.setrgb should be equivalent to d.add(new RGB(...)) You have to make another object
	d.add(new FilledRect(100.0, 150.0, 200.0, 50)); // x y moveto x y lineto ... fill
	d.add(new Rect(100.0, 150.0, 200.0, 50));       // x y moveto x y lineto ... stroke
	for (int x = 0; x < 600; x += 100)
		d.add(new FilledCircle(x,200,50.0)); // x y r 0 360 arc fill
	d.setrgb(0,1,0); // the rest are green

	d.add(new Circle(0,0, 100)); // 0 0 100 0 360 stroke
	d.add(new Line(400,500, 600,550));
	//OPTIONAL+40%	d.add(new Polygon(200,200, 50, 6));
  printIt(d);
}
