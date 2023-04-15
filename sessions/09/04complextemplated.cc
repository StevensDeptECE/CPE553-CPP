#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Complex {
private:
    T real, imag;

public:
   Complex(T r, T i) : real(r), imag(i) {}
   friend Complex operator +(const Complex& a, const Complex& b) {
     return Complex(a.real + b.real, a.imag + b.imag);
   }
   friend ostream& operator <<(ostream& s, const Complex& c) {
     return s << c.real << " + i" << c.imag;
   }
};

int main() {
    {
        Complex<double> a(1.5, 2.1);
        Complex<double> b(2.1, 5.7);
        Complex<double> c = a + b;
        cout << c << '\n';  
    }

    {
        Complex<float>  a(1.1f, -3.6f);
        Complex<float>  b(3.9f, -1.2f);
        Complex<float>  c = a + b;
        cout << c << '\n';  
    }

    {
        Complex<string> a("hello", "there");
        Complex<string> b("good", "bye");
        Complex<string> c = a + b;
        cout << c << '\n';  
    }
}