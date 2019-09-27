#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> a;
	a.reserve(10000);
	for (int i = 0; i < 10000; i++)
		a.push_back(i);
	
	vector<string> words;
	words.push_back("hello");
	words.push_back("goodbye");
	words.push_back("testing");
	
	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << '\t';
	cout << '\n';
	
    for(vector<string>::iterator i = words.begin(); i != words.end(); ++i)
      cout << *i << '\t';
    cout << '\n';

		auto a = 2;
		auto b = 3.0; // double
		auto c = 3.0f; // float

		
    for (auto x : words ) 
      cout << x << '\t';
    cout << "\n";
}
