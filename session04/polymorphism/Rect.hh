#include "Shape.hh"

class Rect : public Shape {
private:
    double w,h; 
public:
    Rect(double x, double y, double w, double h) : Shape(x, y), w(w),h(h) { }
    double area() const override {
        return w*h;
    }
    double perimeter() const override {
        return 2*(w + h);
    }
    void print(std::ostream& s) const override {
        s << "perimeter" << perimeter() ;
        
    }
};
//🅱️