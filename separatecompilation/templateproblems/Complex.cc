#include "Complex.hh"

template<typename T>
void Complex<T>::big(int n) {
    // this is a big function. I don't want it to be inline
    for (int i = 0; i < n; i++) {
        real++;
        imag += real;
    }
}

Complex<double> c1(1,2);
Complex<float> c2(1,2);
