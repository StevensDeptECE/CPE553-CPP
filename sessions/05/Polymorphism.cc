#include <iostream>
#include <vector>
using namespace std;
#if 0
Car: speed, color
Bus: speed, numpassengers
Truck: speed, weight

Circle : r
	area()
	perimeter()
	
Rect: width, height
	area()
	perimeter()
#endif

const double PI = 3.14159265358979;
#if 0
public abstract class Shape {
  public double area();
}

public class Circle extends Shape {
}

public final class A {

}
#endif

class Shape {
public:
  virtual double area() const  = 0;
  virtual double perimeter() const = 0;   
};

class Circle : public Shape { // A Circle is a kind of Shape
private:
  double r;
public:
   Circle(double r) : r(r) {}
   double area() const  { return PI * r*r; }
   double perimeter() const { return 2*PI*r; }   
};

class Rect : public Shape { // A Rect is a Shape
 private:
   double L, W;
 public:
   Rect(double L, double W) : L(L), W(W) {}
   double area() const { return L*W; }
   double perimeter() const { return 2*(L+W); }
 };
   
int main() {
     const Circle c(5);
	 cout << c.area() << '\n';
	 cout << c.perimeter() << '\n';
	 Rect r(4.5, 5);
	 cout << r.area() << '\n';
	 cout << r.perimeter() << '\n';
	 
// illegal to create a shape, it is ABSTRACT	 Shape s; 
	 vector<Shape*> shapes;
	 shapes.push_back(new Circle(5));
	 shapes.push_back(new Rect(3, 4));
	 for (auto s : shapes) {
	   cout << s -> area() << '\n'; // calls the correct method of either Circle or Rect polymorphically
	   }
     cout << sizeof(Shape) << '\n';	   
     cout << sizeof(Circle) << '\n';	   
}
