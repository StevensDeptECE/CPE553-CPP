#include <iostream>
using namespace std;


class LinkedList {
private:
	class Node { // LinkedList::Node
	public:
		int data;
		Node* next;
		Node(int v, Node* n) : data(v) {}
	};
	Node* head;
public:

	LinkedList() : head(nullptr) {}
	~LinkedList() {
		Node* q;
		for (Node* p = head; p != nullptr; p = q) {
			q = p->next;
			delete p;
		}
	}
	// if you do not want to implement copy constructor use =delete (C++11)
	//	LinkedList(const LinkedList& orig)  = delete;
	//	LinkedList& operator =(const LinkedList& orig) = delete;
	//	LinkedList(LinkedList&& orig) {}
	LinkedList(const LinkedList& orig) {
		if (orig.head== nullptr) {
			head = nullptr;
			return;
		}
		head = new Node(orig.head->data, nullptr);
		Node* p = orig.head->next;
		if (p == nullptr)
			return;
		// there are at least 2 nodes
		Node* q = head;
		for (; p != nullptr; p = p->next, q = q->next)
			q->next = new Node(p->data, nullptr);
	}
	
	LinkedList& operator =(LinkedList copy) {
		swap(head, copy.head);
		return *this;
	}

	/*
          _______
		temp->| data| 
          | next|--> head
          -------
	 */
	void addStart(int v) {
#if 0
		Node* temp = new Node();
		temp->data = v;
		temp->next = head;
		head = temp;
#endif
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
		// p = pointing to the last element
		p->next = new Node(v, nullptr);
	}
	friend ostream& operator <<(ostream& s, const LinkedList& list) {
		for (Node* p = list.head; p != nullptr; p =p->next)
			s << p->data << ' ';
		return s;
	}
};


int main() {
	LinkedList a; // a is empty
	a.addStart(3);
	a.addEnd(1);
	a.addStart(4);
	cout << a;

}
