#include "derived1.hh"
#include "derived2.hh"
#include <vector>
using namespace std;

int main() {
  vector<base*> mylist;
  mylist.push_back(new derived1());
  mylist.push_back(new derived2());
  mylist.push_back(new derived1());

  // this just calls one function:  int y = f(x);
  for (int i = 0; i < mylist.size(); i++)
    mylist[i]->f(); //polymorphic call: depending on what you are, I will call the right method f

  for (auto x : mylist)
    x->f();
}
