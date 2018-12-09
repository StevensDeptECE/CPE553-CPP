#pragma once

class LinkedListBase {
protected:
	class Node { // LinkedList<T>::Node
	public:
		Node* next;
		Node(const T& v, Node* n) : val(v), next(n) {}
	};
	Node* head;
public:
	LinkedListBase() : head(nullptr) {}
	~LinkedListBase();
};

template<typename T>
class LinkedList : public LinkedListBase {
private:
	class Node : LinkedListBase::Node { // LinkedList<T>::Node
	public:
		T val;
		Node(const T& v, Node* n) : val(v), next(n) {}
	};
public:
  LinkedList() : LinkedListBase() {}
	//	~LinkedList() : LinkedListBase() {}
	LinkedList(const LinkedList& orig);
	LinkedList& operator=(const LinkedList& orig);

	void addStart(const T& v) {

	}
	void addEnd(const T& v) {}
	friend ostream& operator <<(ostream& s, const LinkedList& list) {

	}
};
