#pragma once

#include <iostream>

class Complex {
private:
  double real, imag;
public:
    Complex(double r, double i) : real(r), imag(i) {
    }
    void big(int n);
    
    friend Complex operator +(const Complex& a,
                              const Complex& b);

    friend std::ostream& operator <<(std::ostream& s, const Complex& c);

};