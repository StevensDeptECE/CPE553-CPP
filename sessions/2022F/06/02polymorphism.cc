#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class shape {
private:
    double x, y, z;                 //  position
public:
    shape() : x(0), y(0), z(0) {}
    virtual void print(ostream& os) const = 0;
};

class cylinder : public shape {
private:
    double r, h;
public:
    cylinder(double rad, double height) : r(rad), h(height){}
    void print(ostream& os) const override{}
    friend ostream& operator << (ostream& os, const cylinder cyl){
        return os << "radius= " << cyl.r << "\t\theight= " << cyl.h << endl;
    }
};
class cube : public shape {
    private:
        double length, breadth, height;
    public:
        cube(){
            length = breadth = height = 0;
        }
        cube(double length, double breadth, double height) : length(length), breadth(breadth), height(height){}
        void print(ostream& os) const override{
        
        }
        friend ostream &operator <<(ostream &os , const cube &c){
            return os << "<" << c.length << "," << c.breadth << "," << c.height << ">";
        }
};

class model {
private:
  vector<shape*> shapes;
  ofstream file;
public:
  model(const char filename[]) : file(filename) {
//    file.open(filename);
  }
    // clean up when we're done
  ~model() {
    for (auto s : shapes)
      delete s;

  }
  void add(shape* s) {
    shapes.push_back(s);
  }
  void print() {
    for (auto s : shapes)
      s->print(file);
  }

};

int main() {
  cube c1(1,2,3);
  cout << c1;
  cylinder c2(10, 30);
  cout << c2;

  model m("test1.stl");
  // Don't do this: m.add(&c1);
  m.add(new cube(4,5,6));
  m.add(new cylinder(10, 20));
}