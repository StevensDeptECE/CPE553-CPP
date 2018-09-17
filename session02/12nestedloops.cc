#include <iostream>
using namespace std;

/*
	1 2 3 4
  2 4 6 8
  3 6 9 12
 */
int main() {
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 4; j++) {
			cout << i*j << ' ';
		}
		cout << '\n';
	}
}
			
