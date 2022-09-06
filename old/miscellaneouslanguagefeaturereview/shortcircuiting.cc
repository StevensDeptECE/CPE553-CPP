#include <iostream>
using namespace std;

bool f() {
	cout << "hello";
	return true;
}

int main() {
  if (4 < 3 && f()) // short-circuiting
		cout << "did this happen?";

	if (3 < 4 || f()) { // short-circuiting
		cout << "did this happen2?";
	}

	int x[10];

	int i = 19;
	if (i < 10 && x[i] == 63) {

	}


	return 0;
}
