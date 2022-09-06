#include <vector>
#include <list>
using namespace std;

int main() {
	vector<int> a;
	const int n = 1000000;
	for (int i = 0; i < n; i++)
		a.push_back(i);
  
	// a.size() // O(n^2)
	for (int i = 0; i < a.size(); i++)
		cout << a[i]; // O(n^2)


	for (vector<int>::iterator i = a.begin(); i != e.end(); ++i)
		cout << *i;
	
  for (const auto& x : a) {
    cout << x;
	}
}
