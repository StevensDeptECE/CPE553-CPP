#include <random>
/*
	Implement the functions above main

 */

int main() {
	constexpr int n = 16;
	double v1[n], v2[n], v3[n], v4[n]
		
	sin(v1, n); // set the points of the x array to sampled values of sine
	print(v1, n); // print out all n values rounded to 3 digits
	
	linear(v2, n, 1.2, 5.8); // set the values of x to be linear starting with 1.2 and ending with 5.8
	print(v2, n); // print out all n values rounded to 3 digits
	
	sin_with_noise(v3, n, 0.1); // generate a sine wave with normally distributed noise, variance = 0.1
	print(v3, n);
}
	
