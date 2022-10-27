#include <cstdint>

int f1a(int a, int b) {
	return a + b;
}

int f1b(int a, int b) {
	return a - b;
}

int f1c(int a, int b) {
	return a * b;
}

int f1d(int a, int b) {
	return a / b;
}

uint64_t f2a(uint64_t a, uint64_t b) {
	return a + b;
}

uint64_t f2b(uint64_t a, uint64_t b) {
	return a - b;
}

uint64_t f2c(uint64_t a, uint64_t b) {
	return a * b;
}

uint64_t f2d(uint64_t a, uint64_t b) {
	return a / b;
}


double f3a(double a, double b) {
	return a / b;
}



double handopt1(double x) {
	return 3 * x * 2;
}

double handopt2(double x) {
	return 3 * x / 2;
}


