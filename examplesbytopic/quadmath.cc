/*
	Test code generation for quadmath and builds some sample functions
	such as findEpsilon to test machine parameters in
	single, double and quad precision

	g++ -O3 quadmath.cc -lquadmath

	g++ -O3 -S quadmath.cc
 */

#include <iostream>
#include <cmath>
#include <quadmath.h>
#include <iostream>
#include <time.h>
using namespace std;

ostream& operator <<(ostream& s, __float128 q) {
  char buf[64];
  quadmath_snprintf(buf, sizeof(buf), "%Qf", q);
	return s;
}

__float128 f(__float128 x) { return x*x; }

template<typename Precision>
Precision findEpsilon() {	
	Precision x;
    Precision last;
	for ( x = 1; 1+x > x; last = x, x *= 0.5) {
		if (x == 0)
			break;
	}
	return last;
}

template<typename Precision>
Precision f1(Precision x, Precision y) {
	return x + y;
}

template<typename Precision>
Precision f2(Precision x, Precision y) {
	return x - y;
}

template<typename Precision>
Precision f3(Precision x, Precision y) {
	return x * y;
}

template<typename Precision>
Precision f4(Precision x, Precision y) {
	return x / y;
}

template<typename Precision>
Precision unary1(Precision x) {
	return -x;
}

template<typename Precision>
Precision unary2(Precision x) {
	return +x;
}

__float128 unary3(__float128 x) {
	return cosq(x) + sinq(x);
}

__float128 unary4(__float128 x) {
	return expq(x) + logq(x);
}

__float128 unary5(__float128 x) {
	return fabsq(x);
}

__float128 unary6(__float128 x) {
	return fabsq(x);
}

double unary3(double x) {
	return cos(x) + sin(x);
}

double unary4(double x) {
	return exp(x) + log(x);
}

double unary5(double x) {
	return fabs(x);
}
	
#define generateAll(funcName)   \
template __float128 funcName<__float128>(__float128,__float128); \
template double funcName<double>(double, double);                \
template float funcName<float>(float, float);                    \
template uint32_t funcName<uint32_t>(uint32_t, uint32_t);        \
template uint64_t funcName<uint64_t>(uint64_t, uint64_t);        \
template __int128 funcName<__int128>(__int128, __int128)

#define generateAllUnary(funcName)                    \
template __float128 funcName<__float128>(__float128); \
template double funcName<double>(double);             \
template float funcName<float>(float);                \
template uint32_t funcName<uint32_t>(uint32_t);       \
template uint64_t funcName<uint64_t>(uint64_t);       \
template __int128 funcName<__int128>(__int128)

generateAll(f1);
generateAll(f2);
generateAll(f3);
generateAll(f4);

generateAllUnary(unary1);
generateAllUnary(unary2);

template<typename Precision>
Precision sum(Precision a, Precision b) {
	Precision s = 0;
	for (Precision x = a; x <= b; x++)
		s += x;
	return s;
}

template<typename Precision>
Precision prod(Precision a, Precision b) {
	Precision p = 1;
	for (Precision x = a; x <= b; x++)
		p *= x;
	return p;
}

template<typename Func, typename T>
void benchmark(const char funcName[], const char type[], uint64_t n, Func func, T start, T end) {
	clock_t t0 = clock();
	func(start, end);
	clock_t t1 = clock();
	cout << funcName << " " << type << ": elapsed=" <<  (t1-t0)*1e-6 << endl;
}

#define bench(T, n, func)											\
	benchmark(#func, #T, n, func<T>, T(1), T(n))

int main()
{
	cout << "single precision eps:" <<  findEpsilon<float>() << '\n';
	cout << "Double precision eps:" <<  findEpsilon<double>() << '\n';
	cout << "Quad precision eps:" <<  findEpsilon<__float128>() << '\n';

	constexpr uint64_t n = 1000000000; // 1 billion
	//bench(float, n, sum);
	bench(double, n, prod);
	bench(__float128, n, prod);
	bench(__int128, n, prod);
	bench(uint64_t, n, prod);
	bench(uint32_t, n, prod);
  return 0;
}
