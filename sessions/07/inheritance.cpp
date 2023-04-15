#include <iostream>
using namespace std;

class A {};

class B {
private:
    uint32_t a; // 4 bytes
    uint8_t x;  // 1 byte
    // inserts 3 bytes of dead space to align to 8 bytes
protected:
    void g() {}
public:
    B() {}
    void f() {}
    void h() {}
    void f2() {}
};
/*
public inheritance
    whatever is private in my parent is INVISIBLE
    whatever is protected is protected
    whatever is Public in my parent is PUBLIC    
*/
class C : public B { // class C IS_A B or (IS_A KIND OF)
private:
   uint64_t y; // 8 bytes
};

/*
private inheritance:
  what is private in the parent is INVISIBLE
  protected and public --> private

class D : private B {

}

class D {
    private:
       B impl;
}

protected inheritance
private in the parent is INVISIBLE
protected --> protected
public  --> protected

class E : protected B {

};

class E {
    protected:
       B impl;
}
*/

class Airplane {
    private:
    double fuel;
    double fuel_burn;
  public:
  Airplane(double initial_fuel, double fuel_burn) : 
  fuel(initial_fuel), fuel_burn(fuel_burn) {}
  void crash() {
    cout << "boom";
  }
  void fly() {
    fuel--;
    if (fuel <= 0)
      crash();
  }

};

class PassengerPlane : public Airplane {
    private:
    double coffee;
public:
  PassengerPlane(double initial_fuel, double fuel_burn, double initial_coffee) :
   Airplane(initial_fuel, fuel_burn) {
    coffee = initial_coffee;
  }
  void fly() {
    cout << "serving coffee";
    coffee--;
    if (coffee <= 0)
      cout << "riot";
    Airplane::fly();
  }
};

class B777 : public PassengerPlane {
public:
  B777(double fuel, double coffee) : PassengerPlane(fuel, 0.5, coffee) {}
};
int main() {
    Airplane a(100, 2.5);
    for (int i = 0; i < 100; i++)
        a.fly();
    PassengerPlane p(100, 1, 50);
    for (int i = 0; i < 50; i++)
      p.fly();
    B777 plane1(100, 6000);

}

