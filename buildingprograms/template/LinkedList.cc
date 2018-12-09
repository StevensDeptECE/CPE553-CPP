#include "LinkedList.hh"

LinkedListBase::~LinkedListBase() {
	for (Node* p = head; p != nullptr; ) {
		Node* temp = p;
		p = p->next;
		delete temp;
	}
}
