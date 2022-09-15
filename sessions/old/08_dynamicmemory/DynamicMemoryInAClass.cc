#include <cstdint>

class Vec3d {
public:
  double x,y,z;
  Vec3d(double x_ = 0, double y_ = 0, double z_ = 0) : x(x_), y(y_), z(z_) {}

  // you do not have to write this. The compiler writes it for you!
  //  Vec3d(const Vec3d& orig) : x(orig.x), y(orig.y), z(orig.z) {}


  //this is the defualt. no need to write
  //  Vec3d& operator = (const Vec3d& orig) {
  //  x = orig.x;
  //  y = orig.y;
  //  z = orig.z;
  //  return *this;
  // }
};


/*
  The style of using an object to track a resource 
  is called RAII

  Resource Allocation Is Initialization

 */

class Thing {
private:
  int* const a;
  const int b;
  int size;
public:
  Thing() : a(nullptr), b(19), size(0) {}
  Thing(uint32_t size) : a(new int[size]), b(5), size(size) {
    for (int i = 0; i < size; i++)
      a[i] = 3;
    //    a = new int[size]; these would be illegal because they are const
    //    b = 5;
  }
  ~Thing() {
    delete [] a;
  }
  // option 1: disable copying this object
  //  Thing(const Thing& orig) = delete;
  //  Thing& oeprator =(const Thing& orig) = delete;

  Thing(const Thing& orig) : a(new int[orig.size]), b(5), size(orig.size) {
    for (int i = 0; i < size; i++)
      a[i] = orig.a[i];
  }

  // there is a newer way to do operator = (copy and swap)
  // operator = writes over an existing object
  Thing& operator =(const Thing& orig) {
    if (this != &orig) {
      delete [] a; // prevent memory leak
      a = new int[orig.size];
      size = orig.size;
      for (int i = 0; i < size; i++)
	a[i] = orig.a[i];
    }
    return *this;
  }

  
  // move constructor
  Thing(Thing&& orig) : a(orig.a), b(orig.b), size(orig.size) {
    orig.a = nullptr;
  }
};

  //move constructor makes this faster
Thing f() {
  Thing x(1000);
  return x;
}

int main() {
  Thing a(1000);
  Thing b = a; // calls copy constructor
  b = a; // operator =
  a = a;

  Vec3d v1(1,2,3);
  Vec3d v2(1,2); // z=0
  Vec3d v3(1); // y=0, z=0
  Vec3d v4; // x = y = z = 0
  //ILLEGAL:  Vec3d v5(,,3); // NOT!
  Vec3d v5 = v1; //copy constructor
  Vec3d v6(v1); // copy
  v5 = v6 = v2; // operator = is NOT THE SAME as the constructor
  
}
