#include <iostream>
#include <cmath>
#include <numbers>
using namespace std;

// Shape is an abstract class
class Shape {
public:
// an abstract method in object oriented programming does not exist
    virtual double area() const = 0; // pure virtual function
    virtual void print(ostream& s) const = 0; 
    friend ostream& operator <<(ostream& s, const Shape& shape);
};

ostream& operator <<(ostream& s, const Shape& shape) {
    shape.print(s);
    return s;
}

// all circles contain a pointer to the Circle Virtual Function Table
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double radius) : radius(radius) {}
    double area() const override { return std::numbers::pi * radius * radius; }
    void print(ostream& s) const override {
        s << "Circle radius=" << radius << '\n';
    }
};

// all Rect contain a pointer to the Rect Virtual Function Table
class Rect : public Shape {
private:
    double len, wid;
public:
    Rect(double len, double wid) : len(len), wid(wid) {}
    double area() const override  { return len * wid; }
    void print(ostream& s) const override {
        s << "Rect L=" << len << " W=" << wid << '\n';
    }
};

int main() {
//    Shape s; // cannot INSTANTIATE an object of that type
    const Circle c(3);
    cout << c.area() << '\n';
    const Rect r(5, 4);
    cout << r.area() << '\n';

    const Shape* array[3] = {&c, &r, new Circle(4)   };
    for (int i = 0; i < 3; i++) {
       cout << (*array[i]).area() << '\n';
    }
    for (auto s : array) {
        cout << *s;
    }
}


