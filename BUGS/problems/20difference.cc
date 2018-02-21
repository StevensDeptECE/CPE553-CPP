#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float temp1 = 70.00001;
	float temp2 = 70.00000;
	cout << setprecision(8) << temp2-temp1 << '\n';
	//  my computer reports a result of -7.6293945e-006
	// what is wrong with this answer?
}
