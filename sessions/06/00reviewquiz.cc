#include <iostream>
using namespace std;
//1. recursive function fibo

double fibo(uint64_t n){
  if (n <3 ) {
    return 1;
  }
  return fibo(n-1) + fibo(n-2);
}

// 2. Write vector class
class Vector {
private:
    double x,y,z;
#if 0
    Vector(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
#endif
public:
    Vector(double x, double y, double z) : x(x), y(y), z(z) {
    }
    // declaration
    friend Vector operator +(Vector a, Vector b);
    friend Vector operator -(Vector a, Vector b);
    friend Vector operator -(Vector a);
    // left hand side is called this
    Vector add(Vector b) const {
        return Vector(this->x+b.x, y+b.y, z+b.z);       
    }
    friend ostream& operator <<( ostream& s, Vector v ) {
        return s << v.x << "," << v.y << "," << v.z;
    } 
};


//definition (only once)
Vector operator +(Vector a, Vector b) {
  return Vector(a.x+b.x, a.y+b.y, a.z+b.z);       
}    

Vector operator -(Vector a, Vector b) {
  return Vector(a.x-b.x, a.y-b.y, a.z-b.z);       
}    

Vector operator -(Vector a) {
  return Vector(-a.x, -a.y, -a.z);       
}    


int main() {
    const Vector v1(1,2,3);
    Vector v2(2,3,5.2);
   // Vector a(2,3);
   // Vector b(3);
//ERROR:    Vector c("hello", "test", "999");
    //Vector d;
    Vector e(); // e is NOT AN OBJECT e is a function prototype
   // e.add(v1)
    Vector v3 = v1 + v2;
    Vector v4 = -v1;
    Vector v5 = v1.add(v2);
    cout << "hello" <<  v5;
}