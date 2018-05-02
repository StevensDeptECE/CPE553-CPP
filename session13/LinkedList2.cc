#include <iostream>
#include <vector>
using namespace std;

class LinkedList {
private:
	class Node { // LinkedList<T>::Node
	public:
	  int val;
		Node* next;
		Node(int val, Node* next) : val(val), next(next) {}
	};
  Node* head; 
public:
	LinkedList() : head(nullptr) {}
 	~LinkedList() {
		Node* q;
		for (Node* p = head; p != nullptr; ) {
			q = p;
			p = p->next;
			delete q;
		}
	}
	LinkedList(const LinkedList& orig) = delete;
	LinkedList& operator =(const LinkedList& orig) = delete;
	
	void addStart(int v) {
		head = new Node(v, head);
	}

	void addEnd(int v) {
		if (head == nullptr) {
			head = new Node(v, nullptr);
			return;
		}
		Node* p;
		for (p = head; p->next != nullptr; p = p->next)
			;
		// p is guaranteed to point to last element
		p->next = new Node(v, nullptr);		
	}
	class ConstIterator {
	private:
		Node* current;
	public:
		ConstIterator(const LinkedList& list): current(list.head) {}
		bool operator !() const {
			return current != nullptr;
		}
		operator ++() {
			current = current->next;
		}
		//		operator ++(char* garbage) postincrement
    int operator *() const {
      return current->val;
		}
	};
	class Iterator {
	private:
		Node* current;
	public:
		Iterator(LinkedList& list): current(list.head) {}
		bool operator !() const {
			return current != nullptr;
		}
		operator ++() {
			current = current->next;
		}
		//		operator ++(char* garbage) postincrement
    int& operator *() const {
      return current->val;
		}
	};

	friend ostream& operator <<(ostream& s, const LinkedList& list) {
		for (Node* p = list.head; p != nullptr; p = p->next) {
      s << p->val << ' ';
		}
		return s;
	}
};


int main() {
	LinkedList a;
	//not allowed, explicitly deleted	LinkedList b = a;
	for (int i = 0; i < 10; i++)
		a.addStart(i);
	for (int i = 0; i < 10; i++)
		a.addEnd(i);
	cout << a << '\n';

#if 0
	for (LinkedList::Iterator i = a; i.hasNext(); i.next())
		cout << i.getValue() << ' ';
	cout << '\n';
#endif

	for (LinkedList::ConstIterator i = a; !i; ++i)
		cout << *i << ' ';
	cout << '\n';

	for (LinkedList::Iterator i = a; !i; ++i)
		*i *= 2;

	for (LinkedList::ConstIterator i = a; !i; ++i)
		cout << *i << ' ';
	cout << '\n';

	vector<int> x = {1, 2, 3};
	for (vector<int>::iterator i = x.begin(); i != x.end(); ++i)
		cout << *i;
	cout << '\n';
		
}
