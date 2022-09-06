#include <iostream>
#include <random>
using namespace std;

constexpr double pi = 3.14159265358979;
/*
	generator provides a pseudo-random source of bits
	It looks random, but if we start it off with a known value, the program will generate
	the same random-looking sequence every time.
	For testing, being able to repeat is good. Start this way, and when your program works, then replace
	by seeding the generator from the time.
*/

default_random_engine generator(0); // seed with 0 for repeatable pseudorandom values
//default_random_engine generator; // replace the previous with this line for different results every time

int main() {
	uniform_int_distribution<int> distribution(1,6);

	// this is how to get random integers out of the generator
	for (int i = 0; i < 10; i++) {
		int roll = distribution(generator);  // random range [1,6]
		cout << roll << " ";
	}
	cout << '\n';
	// for double precision uniform random numbers, use the following
	uniform_real_distribution<double> dist(0.0,1.0);
	for (int i = 0; i < 10; i++) {
		double r = dist(generator);
		cout << r << ' ';
	}
	cout << '\n';

	// the following generates uniformly distributed angles from 0 to 2pi
	uniform_real_distribution<double> randAngle(0.0,2*pi);
	for (int i = 0; i < 10; i++) {
		double r = randAngle(generator);
		cout << r << ' ';
	}
	cout << '\n';


	// the library also supports other distributions that are not uniform
	
	normal_distribution<double> N(0.0, 1.0);
	// the following generates uniformly distributed angles from 0 to 2pi
	for (int i = 0; i < 10; i++) {
		double r = N(generator);
		cout << r << ' ';
	}
	cout << '\n';
	

}
