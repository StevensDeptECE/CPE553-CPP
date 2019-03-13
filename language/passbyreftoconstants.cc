#include <iostream>
#include <string>
using namespace std;

class Person {
private:
  string firstName, lastName;
  int age;
public:
  Person(string& firstName, const string& lastName, int& age) :
firstName(firstName), lastName(lastName), age(age) {}
  friend ostream& operator <<(ostream& s, const Person& p) {
    return s << p.firstName << " " << p.lastName << " " << p.age;
	}
};
int main() {
  Person a("Steve", "Rogers", 60);
  cout << a << "\n"; // output should be “Steve Rogers 60”
}
