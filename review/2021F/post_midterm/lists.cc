#include <vector>
using namespace std;

int main() {
	vector<int> a;
	a.push_back(3);
	a.push_back(1);
	a.push_back(4);
	a.push_back(1);
	a.push_back(5);
	for (auto x : a) {
		cout << x;
	}
	for (auto x : a) {
		cout << x;
	}
