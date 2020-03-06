#include <iostream>
#include <vector>
using namespace std;

class Shape {
private:
	
public:
	virtual void print() const = 0;
};
class Rect : public Shape {
private:
	int w, height;
public:
	Rect(int w, int h) : w(w), height(h) {}
	void print() const override {
    cout << "Rect " << w << " " << height;		
	}
};

class Circle :public Shape {
private:
	int r;
public:
	Circle(int r) : r(r) {}
	void print() const override {
		cout << "Circle " << r;
	}
};

int main() {
	vector<Shape*> shapes;
	shapes.push_back(new Rect(30, 40));
	shapes.push_back(new Circle(20));
	shapes.push_back(new Rect(30, 40));

	for (auto s : shapes) {
		s->print();
	}
}
