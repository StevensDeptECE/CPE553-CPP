#pragma once
#include <iostream>
template<typename T>
class LinkedList {
private:
	class Node { // LinkedList<T>::Node
	public:
		T val;
		Node* next;
		Node(const T& v, Node* n) : val(v), next(n) {}
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
	LinkedList(const LinkedList& orig) {
		if (orig.head == nullptr) {
			head = nullptr;
			return;
		}
		Node* p = orig.head;
		head = new Node(p->val, nullptr);
		p = p->next;
		Node* copy = head;
		while (p != nullptr) {
			copy->next = new Node(p->val, nullptr);
			copy = copy->next;
			p = p->next;
		}
	}
	LinkedList& operator=(const LinkedList& orig) {
    LinkedList copy(orig);
		swap(head, copy.head);
		return *this;
	}

	void addStart(const T& v) {
    head = new Node(v, head);
#if 0
		// this is equivalent of the one line constructorr
		Node* temp = new Node();
		temp->val = v;
		temp->next = head;
		head = temp;
#endif
	}

	void addEnd(const T& v) {
		if (head == nullptr) {
			head = new Node(v, nullptr);
			return;
		}
		Node* p;
		for (p = head; p->next != nullptr; p=p->next)
			;
		// guaranteed p points to last element???
		p->next = new Node(v, nullptr);
		
		
	}
	friend std::ostream& operator <<(std::ostream& s, const LinkedList& list) {
    for (Node* p = list.head; p != nullptr; p = p->next)
			s << p->val << ' ';
		return s;
	}
};
