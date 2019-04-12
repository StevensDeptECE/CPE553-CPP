#include <vector>
#include <iostream>

using namespace std;

class Elephant {
private:
	string name;
	int age;
public:
	Elephant(const char name[], int age) : name(name), age(age) {}
	friend ostream& operator <<(ostream& s, const Elephant& e) {
		return s << e.name << ", " << e.age;
	}
};

int main() {
  vector<Elephant> elephants;
	elephants.emplace_back("Fred", 3);
	elephants.emplace_back("Alice", 4);
	for (auto& e : elephants) {
		cout << e << '\n';

	}
}
