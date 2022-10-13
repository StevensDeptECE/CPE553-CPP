// pow(2,8) = 256   pow(2,15) = 32768      pow(2,16) = 65536


// 1. primitive data types. What is printed by the following code? Assume on your laptop not an Arduino
int main() {
  int a;
  cout << a << '\n'; // ____________
  cout << sizeof(a) << '\n'; // ________________
  uint16_t b = 65534;
  b += 3;
  cout << b << " size=" << sizeof(b) << '\n'; // ___________________
  uint64_t c = 0;
  c--;
  c += 2;
  cout << c << " size=" << sizeof(c) << '\n'; // ___________________
  int16_t d = 32766;
  d += 2;
  cout << d << '\n'; // __________________
  int e = 3 + 4 * 5; // e=__________________
  int f = 3 / 2 * 2; // f=__________________
  int g = 2 / 3 * 3; // g=__________________
  int h = 3 * 2 / 3; // h=__________________
  int i = 5 % 4 + 6 % 5 + 7 % 5; // i=______________
}

// 2. Write loops

// write a loop to print powers of 2 up to 512: 1 2 4 8 16 32 64 128 256 512
// write a loop to calculate the product of elements in an array

//3. Write functions
int main() {
  const int a = 1'000'000, b = 2'000'000, s = 3;
  uint64_t s = sum(a, b, s); // sum the integers from a to b inclusive stepping by s

  const int a2 = 300, b2 = 450;
  uint64_t s2 = sumsq(a2, b2, s); // sum the square of the integers from a to b inclusive stepping by s

  double s3 = sum_fibo(20); // return the sum of the fibonacci sequence up to and including the 20th element 1 + 1 + 2 + 3 + 5 + ...
  const double a[] = {3, 1, 2};
  const double b[] = {4, 2, -5.2};
  double m = dot(a, b, sizeof(a)/sizeof(double)); // use a loop in your code. Do not assume length is 3!
}

//4. statements
int main() {
  if (a == b) {

  } else {

  }

  while () {

  }

  while (true) {
     // infinite loop
  }
  for (int i = 0; i < 10; i++)
    ;

    // infinite loop
  for (int i = 0; ; i++)
    ;
}

//4. Write class Fraction, Complex, Vec3d, ... with:
/*
  write method print(ostream& s) where the stream to print on is a parameter to the method
  write operator << to print in the standard way   (cout << myobject << '\n')

  write a friend operator + to implement binary addition     Fraction c = a + b;
  write a member operator - to implment binary subtraction   Fraction d = a - b;

  write a friend operator - to implement unary negation:     Fraction e = -a;
  write a member operator + to implement unary + (does nothing!)  Fraction f = +a; // just copy a!

*/

//5. Polymorphism
// write a pure virtual function making a base class astract
// write a method (member function) that overrides a pure virtual function
// example: shape, circle, rect, area(), perimeter()

//example: shape, circle, rect, draw()  (the postscript homework)


//example: vehicle, car, bus, truck, paytoll() cars pay $15. busses pay $4.  Trucks pay $20/axle
Car c1("red", 55); // car is red, 55 miles per hour
Bus b1(28, 40); // 28 passengers, 40 miles per hour
Truck t1(20000, 5, 85); // truck weighs 20,000 lb, has 5 axles, goes 85 miles per hour
// you should be able to create a vector of vehicle pointers, put a car, bus and truck in it, and make each one payToll.
vector<Vehicle*> ...

class Fraction {
  private:
   int num, den;
   public:
     Fraction(int n, int d) : num(n), den(d) {}
     Fraction(int n) : num(n), den(1) {}
     #if 0
     friend Fraction operator +(Fraction a, Fraction b) {
      return Fraction(a.num*b.den+a.den*b.num, a.den*b.den);
     }
     #endif
     Fraction operator +(Fraction b) const {
      return Fraction (num*b.den + den*b.num, den*b.den);
     }
     #if 0
     operator int() const {
       return num/den;
     }
     #endif
};


class Shape {

public:
  virtual void print(ostream& s) = 0;
  friend ostream& operator <<(ostream& s, const Shape& shape) {
    shape.print(s);
    return s;
  }
};

int main() {
  Fraction a(1,3);
  Fraction b(1,2);
  Fraction c = a + b;
  //Fraction d = a + Fraction(1);
  //Fraction d = int(a) + 1;
  Fraction d = a + 1;
  Fraction e = 1 + a;
}