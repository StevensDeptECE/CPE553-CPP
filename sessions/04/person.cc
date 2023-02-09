#include <iostream>
#include <string>
using namespace std;

class person {
private:
  string first_name, last_name;
public:
  person(const char f_name[], const char l_name[] )
    : first_name(f_name), last_name(l_name) {
  }
  friend ostream& operator <<(ostream& s, const person& a) {
    return s << a.first_name << " " << a.last_name;
  }
};


int main() {
  person a("Mukund", "Iyengar");
  cout << a;


}