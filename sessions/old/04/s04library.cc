#include <vector>
#include <list>
/*
	list of something 
	vector (single block of memory like an array but can grow)
	     inserting at the beginning or the middle very expensive
  list (linked list), slower than vector for building, but much faster
	    for inserting in the middle or beginning

  map         look up x --> y   (tree)
  unordered_map   (hash table)
 */

class Zebra
{
private:
	string name;

public:
	Zebra(const string &name) : name(name) {}
	friend ostream &operator<<(ostream &s, const Zebra &z)
	{
		return s << "Zebra " << z.name;
	}
};

int main()
{
	vector<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(i); // add to the end

	for (int i = a.size() - 1; i >= 0; i--)
		cout << a[i] << ' ';
	cout << '\n';

	list<Zebra> b;
	b.push_back(Zebra("Fred"));
	b.push_back("Alice");

	for (int i = 0; i < b.size(); i++)
		cout << b[i];

	for (list<Zebra>::iterator i = b.begin(); i != b.end(); ++i)
		cout << *i << ' ';

	for (auto x : b)
	{
		cout << x;
	}
}
