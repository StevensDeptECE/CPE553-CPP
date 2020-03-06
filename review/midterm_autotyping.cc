#include <iostream>
#include <vector>

using namespace std;

int main() {
	auto  x = 2;
	int y[] = {5, 4, 2};

	for (auto a : y) {
		cout << a;
	}

	for (auto& a : y) {
		a *= 2;
	}

	for (auto a : y) {
		cout << a;
	}

	vector<int> b;
	b.push_back(2);
	b.push_back(5);
	b.push_back(1);
 	for (vector<int>::iterator i = b.start(); i != b.end(); ++i)
		cout << *i;
	
	for (auto a : b) {
		cout << a;
	}
}
