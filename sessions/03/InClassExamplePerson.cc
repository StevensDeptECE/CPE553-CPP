#include <string>
#include <iostream>

using namespace std;

class Person {
private:
    string n;
    int lbs;

public:
    Person(string name, int weight) : n(name), lbs(weight) {}

    void print() const {
        cout << n << " " << lbs;
    }

    friend Person operator +(Person a, Person b) {
        return Person(a.n+b.n, a.lbs+b.lbs);
    }

};


int main() {
  const Person a("Donald", 240); // name and weight
  const Person b("Ivanka", 125);

  const Person c = a + b; // The child's name is the concated names of the paretns, ie "DonaldIvanka", weight = sum 240+125
  c.print();
//  cout << c;

}