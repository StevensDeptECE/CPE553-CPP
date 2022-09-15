class Shape {
public:
	virtual double area() const = 0;
	virtual double perimeter() const  = 0;
};

class Line : public Shape {
public:
	double area() const { return 0; }
};

class Circle : public Shape {
	double area() const override { return PI * r*r; }
	double perimeter() const override { return 2*PI*r;}

};

Class Rect {

}

int main() {
	Line line1(10,20, 30, 40);
