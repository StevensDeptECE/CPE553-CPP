class LinkedList {
private:
	class Node { // LinkedList<T>::Node
	  int val;
		Node* next;
	};
  Node* head; 
public:
	LinkedList() : head(nullptr) {}
	~LinkedList() {}
	LinkedList(const LinkedList& orig) {}
	LinkedList& operator =(const LinkedList& orig) {}
	
	void addStart(int v) {
		Node* temp = new Node();
		temp->val = v;
		temp->next = head;
		head = temp;
	}

	void addEnd(int v) {
		if (head == nullptr) {
			head = new Node();
			head->val = v;
			head->next = nullptr;
			return;
		}
		Node* p;
		for (p = head; p->next != nullptr; p = p->next)
			;
		// p is guaranteed to point to last element
		Node* temp = new Node();
		temp->val  = v;
		temp->next = nullptr;
		p->next = temp;
		
		
	}
};
