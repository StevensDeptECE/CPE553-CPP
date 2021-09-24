#include <iostream>
#include <vector>
#include <string>

using namespace std;


class robot {
private:
	string name;
	double x,y;

public:
	robot(string name, double x = 0, double y = 0)
		: name(name), x(x), y(y) {}
};

int main() {
	vector<int> mylist;
	mylist.push_back(3);
	mylist.push_back(1);
	mylist.push_back(4);
	for (int i = 0; i < 100; i++)
		mylist.push_back(i);
	
  vector<robot> robots;
  robots.push_back(robot("fred", 1.0, 2.5));
	robots.emplace_back("fred", 1.0, 2.5);

	// string comparison (for homework!)

	string a = "hello";
	a += "test";
	cout << a.length() << '\n';
	
	if (a != "hello") {
		cout << a << '\n';
	}
}
