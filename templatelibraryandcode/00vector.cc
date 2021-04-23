#include <string>
#include <vector>
//#include <list>
#include <iostream>
using namespace std;

class Elephant {

};

void f(const vector<int>& list) {
	for (vector<int>::const_iterator i = list.begin(); i != list.end(); ++i)
		cout << *i << ' ';
	cout << "\n";
}
void g(vector<int>& list) {
	for (vector<int>::iterator i = list.begin(); i != list.end(); ++i)
		*i *= 2;
}

int main(){ 
  vector<int> a;
	vector<string>  b;
	vector<double> c;
	vector<Elephant> d;

 	a.push_back(3);
	a.push_back(5);

	b.push_back("hello");
	b.push_back("test");
	b.push_back("last");

	for (int i = 0; i < a.size(); i++) 
		cout << a[i] << ' ';
	cout << '\n';

	g(a);
	
  f(a);

	for (auto& x : b) {
		x += "x";
	}

  for (const auto& x : b) {
		cout << x << ' ';
	}

	cout << "\n";
}
