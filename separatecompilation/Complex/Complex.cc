#include "Complex.hh"

void Complex::big(int n) {
    // this is a big function. I don't want it to be inline
    for (int i = 0; i < n; i++) {
        real++;
        imag += real;
    }
}

Complex operator +(const Complex& a,
                           const Complex& b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

std::ostream& operator <<(std::ostream& s, const Complex& c) {
    return s << "(" << c.real << "," << c.imag << ")";
}
