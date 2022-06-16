#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
	vector<string> list;
	list.push_back("hello");
	list.push_back("byte");
	list.push_back("test");

	for (auto s : list) {
		for (auto c : s) {
			cout << c;
		}
	}
	string x = list[0];
	cout << x << '\n';
}
