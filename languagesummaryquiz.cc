#include <iostream>
#include <cmath>

using namespace std;

void integeroperations() {
	cout << "Integer Operations\n";
	int a = 2 / 3;         // integer division
	int b = 5 % 4 + 4 % 5 + 3 % 4 + 4 + 3;
	int c = 9 / 4;
	int d = a > 0 ? 6 : 4; // ternary operator
	double e = 1 / 2;

	cout << a << '\t'
			 <<	b << '\t'
			 <<	c << '\t'
			 <<	d << '\t'
			 <<	e << '\n';
}

void operatorprecedence() {
	cout << "Operator Precedence\n";
	int a = 2 + 3 * 4;
	int b = 2 / 3 * 3;
	int c = (int)1.5 * 3;
	int d = 1 << 2 & 1 << 3;
	cout << a << '\t'
			 << b << '\t'
			 << c << '\t'
			 << d << '\n';
}

void overflow() {
	cout << "Overflow\n";
	short a = 32767;
	a++;
	short b = -32767;
	b -= 3;
	int c = 1;
	for (int i = 0; i < 35; i++)
		c <<= 1;
	
	cout << a << '\t' << b << '\t' << c << '\n';
}

void typepromotion() {
	cout << "Type Promotion\n";
	float a = 1.5f * 3;
	double b = 1 * 3;
	cout << a << '\t' << b << '\n';
}

void roundoff() {
	cout << "Roundoff\n";
	double x = sqrt(2);
	
	bool a = x*x == 2;
	cout << a << '\n';
}

void nan() {
	cout << "NaN\n";
	double a = 1.0 / 0.0;
	double b = -1.0 / 0.0;
	double c = 2.0 * a;
	double d = a + b;
	double e = 0.0 / 0.0;
	double f = sqrt(a);
	double g = sin(a);
	cout << a << '\t'
			 << b << '\t'
			 << c << '\t'
			 << d << '\t'
			 << e << '\t'
			 << f << '\t'
			 << g << '\n';
}

void statements() {
	cout << "Statements\n";
	int i = 10;
	while (i < 10) {
		cout << 'x';
	}
	cout << '\n';
	do {
		cout << 'y';
	} while (i < 10);
	cout << '\n';

	for (int i = 2; i < 12; i <<= 1)
		cout << i;
	cout << '\n';

	for (int i = 1; i < 16; i += 3) {
		if (i % 8 == 0)
			break;
		cout << i;
	}
	cout << '\n';

	for (int i = 0; i < 20; i += 4) {
		if (i % 16 == 12)
			break;
		if (i % 2 == 0)
			i++;
		cout << i;
	}
	cout << '\n';

	for (int i = 0; i < 10; i++) {
		if (i % 3 == 0)
			continue;
		cout << i;
	}

	for (int i = 0; i < 5; i++)
		switch(i) {
		case 0: cout << "zero";
		case 1: cout << "one";
		case 2: cout << "two";
		case 3: cout << "three";
		case 4: cout << "four";
		default: cout << "default";
		}
	cout << '\n';

	for (int i = 0; i < 5; i++)
		switch(i) {
		case 0:
			cout << "zero";
			break;
		case 1:
			cout << "one";
			break;
		case 2:
			cout << "two";
			break;
		case 3:
			cout << "three";
			break;
		case 4:
			cout << "four";
			break;
		default:
			cout << "default";
			break;
		}
	cout << '\n';
}

void thedreadedgoto(int n) {
	int countPrimes = 1; // special case for 2
	for (int i = 3; i <= n; i += 2) { // only odd numbers
		int lim = sqrt(i);
		for (int j = 3; j <= lim; j += 2)
			if (i % j == 0)
				goto notPrime;
		countPrimes++; // if all divisors tested, must be prime!
	notPrime: // jump here to skip the prime count and keep going
		;
	}
	cout << "There are " << countPrimes << " primes up to " << n << '\n';
}
		

int main() {
	integeroperations();
	operatorprecedence();
	overflow();
	roundoff();
	nan();
	statements();
	thedreadedgoto(100);
}
