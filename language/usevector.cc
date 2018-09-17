#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(i);

	// reading the elements of a vector using positional notation
	for (int i = 0; i < a.size(); i++)
		cout << a[i];
	cout << '\n';
	
	// reading the elements of a vector using an iterator
	for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
		cout << *i;
	cout << '\n';

	// writing the elements of a vector using an iterator
	// in this case, double the value of each element
	for (vector<int>::iterator i = a.begin(); i != a.end(); ++i)
		*i *= 2;
	
	cout << '\n';

	//using C++11 auto feature wraps the iterator in a slick, easy syntax
	for (auto x : a)
		cout << x;
	for (auto& x : a)
		x *= 2; // doubling again
}
