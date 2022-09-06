#include "Complex.hh"

template <typename T>
inline Complex<T>::Complex(T real, T imag) : real(real), imag(imag) {}
typedef Complex<float> Chicken;

void f() { Complex<int> b(1, 2); }
