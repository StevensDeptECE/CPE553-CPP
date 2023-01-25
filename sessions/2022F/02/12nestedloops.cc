#include <iostream>
#include <iomanip>
using namespace std;

/*
	1 2 3 4
  2 4 6 8
  3 6 9 12
 */
int main() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 6; j++) {
			cout << i*j << '\t';
		}
		cout << '\n';		
	}

	cout << "\n\n\n";
	
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 6; j++) {
			cout <<  setw(5) << i*j;
		}
		cout << '\n';		
	}

}
			
