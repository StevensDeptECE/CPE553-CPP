#include "Complex.hh"

template<typename Precision>
Complex<Precision> operator +(const Complex<Precision>& a, const Complex<Precision>& b) {
	return Complex(a.r+b.r, a.i+b.i);
}

//template<typename T>
//Complex<T>::Complex(...) {}
