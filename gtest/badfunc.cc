#include <iostream>
using namespace std;

double fact(int n) {
	int prod = 1;
	for (int i = 1; i <= n; i++)
		prod *= i;
	return prod;
}

double choose(int n, int r) {
	return fact(n) / (fact(r) * fact(n-r));
}
