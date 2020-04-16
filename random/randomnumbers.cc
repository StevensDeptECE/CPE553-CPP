#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;


//Kruger's rule: always test with a constant seed!!!
// then, when your code works, you can seed from time
default_random_engine generator(2);

double generateUsingRand(uint32_t n) {
	double sum = 0;
	for (int i = 0; i < n; i++) 
		sum += rand();
	return sum;
}

double generateRandomUniform(uint32_t n) {
  uniform_real_distribution<double> U(0.0,1.0);
	double sum = 0;
	for (int i = 0; i < n; i++) 
		sum += U(generator);
	return sum;
}

double generateRandomNormal(uint32_t n) {
  normal_distribution<double> N(0.0,1.0);
	double sum = 0;
	for (int i = 0; i < n; i++) 
		sum += N(generator);
	return sum;
}

int main() {
	/* don't use these random numbers! GARBAGE! */
	//  srand(time(0)); // seed from time
	srand(0); // seed with a constant for testing!
	int a = rand(); // random integer, no standard

	// worst case ever: Borland TurboC++ 3.0
	// 0, 138295 -1356 1412014 ...  138 times 0



	/*
		if you are writing a simulation, you need HONEST RANDOM NUMBERS
    what is random?? see Donald Knuth
		
   in a linear-congruential generator pairs are correlated

   x = rand(), y = rand()
    plot these and you would get lines.

   INSTEAD, use random
	*/

  uniform_int_distribution<int> dist(1,6);
	
	for (int i = 0; i < 100; i++) {
		int die = dist(generator);  // generate
		cout << die << ' ';
	}
	cout << "\n\n";

	const uint32_t n = 50000000;
	clock_t t0 = clock();
	generateRandomUniform(n);
	clock_t t1 = clock();
	cout << "Elapsed: " << (t1-t0) << '\n';

	t0 = clock();
	generateRandomNormal(n);
	t1 = clock();
	cout << "Elapsed: " << (t1-t0) << '\n';

	t0 = clock();
	generateUsingRand(n);
	t1 = clock();
	cout << "Elapsed: " << (t1-t0) << '\n';

#if 0	
	for (int i = 0; i < 100; i++) 
		cout << N(generator) << ' ';
	cout << "\n\n";
#endif
}
