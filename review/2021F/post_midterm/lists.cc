#include <vector>
#include <string>
using namespace std;

class Elephant {
private:
	string name;
	int age;
public:
	Elephant(const char name[], int age) : name(name), age(age) {}

	void setName(const char n[]) {
		name = n;
	}
};


int main() {
	Elephant e("Fred", 3);
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
	cout << '\n';

  for (auto& x : a) {
		x++;
	}
	for (auto x : a) {
		cout << x;
	}
	cout << '\n';

	for (auto& v : a) { // double every element in list
		v = v * 2;
	}
	vector<Elephant> elephants;
	elephants.push_back( Elephant("Bob",3) );
	elephants[0].setName("Alice");
	//	elephants[0].setName("Eve");

	vector<const Elephant> e2;
	e2.push_back( Elephant("Betty", 18));
	e2.push_back( Elephant("Joe", 41));
	// NOT LEGAL, Elephants are const	e2.setName("Fred");

	
  

	
