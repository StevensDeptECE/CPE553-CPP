#include <iostream>
#include <random>
using namespace std;

default_random_engine generator;

int main() {
	int n;
	cout << "please enter number of times to iterate: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		uniform_int_distribution<int> distribution(1,6);
		int dice_roll = distribution(generator);
		cout << dice_roll << ' ';
	}
}
	
