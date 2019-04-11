#include <iostream>
#include <vector>

using namespace std;

class Test {
public:
	Test() { cout << "constructor\n"; }
	~Test() { cout << "destructor\n"; }
};

int main() {
	vector<Test> a;
	a.push_back(Test());
	a.push_back(Test());

	cout << "STARTING\n";
	a.erase(a.begin());
	cout << "ENDING\n";
}
