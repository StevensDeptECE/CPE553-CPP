#include <iostream>
using namespace std;

int main() {
	long long sum = 0;
	for (long long i = 0; i < 10000000000L; i++)
		sum += i;
	cout << "hello" << sum;
}
