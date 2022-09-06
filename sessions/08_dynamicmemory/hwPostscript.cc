#include <iostream>
#include <vector>
#include <fpstream>
using namespace std;

class Shape {
public:
	virtual void draw(ostream& s) = 0;
};

class Circle : public Shape {
public: // x y r 0 360 arc fill
};

class Rect : public Shape {
public:  // x y moveto x+w y lineto x+w y+h lineto x y+h lineto closepath fill
};

int main () {
	vector<Shape*> shapes;
	shapes.push_back(new Circle(100,100, 50));
	shapes.push_back(new Rect(150,300, 200, 100));
	ofstream f("test.ps");
	for (auto s : shapes) {
		s->draw(f);
}
