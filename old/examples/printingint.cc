#include <iostream>
using namespace std;

void print(int a) {
	char buf[11];
	char*p = &buf[10];
	do {
		*p = a % 10 + '0';
		a /= 10;
	} while (a != 0);
}

uint32_t digits[10000] = {
};

void setup() {
	for (int i = 0; i < 10000; i++) {
		digits[i] = (i / 1000 + '0') | ((i / 100 % 10 + '0') << 8) | (( i / 10 % 10 + '0') << 16) | ((i % 10 + '0') << 24);
	}
}

inline void printLeading2digits(uint32_t n) {
	if (n >= 10) {
		const char* p = (char*)&digits[n];
		cout << p[2] << p[3];
	}
}

inline void printLeading10k(uint32_t n) {
	if (n >= 100) {
		
	} else {
		const char* p = (char*)&digits[n];
		cout << p[2] << p[3];
	}
}

inline void print10k(uint32_t n) {
	const	char* p = (char*)&digits[n];
	cout << p[0] << p[1] << p[2] << p[3];
}


void fastPrint(uint32_t n) {
	if (n >= 10000) {
		printLeading10k(n/10000);
		print10k(n%10000);
	} else {
		printLeading10k(n/10000);
	}
}

int main() {
	int a = 123456789;

	print(a);
}
