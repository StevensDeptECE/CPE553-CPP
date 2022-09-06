const double PI = 3.1415926535897932;

class Shape2D {
public:
	virtual double area() const = 0; // every 2d shape must have an area (does not change the object)
	virtual double perimeter() const = 0; // every 2d shape must support perimeter (same)
};

class Circle : public Shape2D {
private:
	double r;
public:
	double area() const override { return PI * r*r; }
	double perimeter() const override { return PI * 2 * r; }
	Circle(double r) : r(r) {}
};

int main() {
	Circle c1(5);
}
