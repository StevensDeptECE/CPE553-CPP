#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a;
	const int n = 100000000;
	a.reserve(n);
	for (int i = 0; i < n; i++)
		a.push_back(i);
	cout << a.size() << '\n';
}
	
