#include <iostream>
using namespace std;

template<typename T>
class Complex {
private:
    T real;
    T imag;
public:
    Complex(T real, T imag) : real(real), imag(imag) {}
    friend Complex operator +(Complex a, Complex b) {
        return Complex(a.real+b.real, a.imag+b.imag);
    }

    
    friend ostream& operator<< (ostream& s, Complex<T> c){
        return s << c.real << ' ' << c.imag;
    }

};

int main() {
    Complex<double> a1(1.0, 2.5);
    Complex<double> a2(2.1, 3.2);
    Complex<float>  b(1.5, 2.5);
    Complex<int>    c(2,3);
    Complex<long double> d(1.2L, 2.5L);

    Complex<double> a3 = a1 + a2;
    // This would not work: different types....  d = a1 + a3;
    cout << a1 << '\n';
    cout << b << '\n';
    cout << c << '\n';
    cout << d << '\n';

}
