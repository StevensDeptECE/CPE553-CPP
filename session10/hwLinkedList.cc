
class LinkedList2 {
private:
	class Node { // LinkedList::Node
	public:
		int val;
		Node* next;
	};
	Node* head;
	Node* tail;
public:
	LinkedList();
	~LinkedList() ;
	LinkedList(const LinkedList& orig);
	LinkedList& operator =(const LinkedList& orig);
	// move constructor
	LinkedList(LinkedList&& orig) { // steal orig data while it's dying (nice)

	}
	void addStart(int v);
	void addEnd(int v);
	void removeStart();
	void removeEnd();
};
/**
  head --> nullptr

  head --> [ val=3 next= nullptr  ]

  head -->  [val=1 next= ---->  [ val=3 next= nullptr  ]



 */
int main() {
	LinkedList2 a;
	a.addStart(3); // 3 is the first element in the list
	a.addStart(1); // 1  3
	a.addStart(4); // 4 1 3
	a.addEnd(1);
	cout << a << '\n'; // print out the list
	LinkedList2 b = a;
  cout << c << '\n';
	LinkedList2 c;
	c.addStart(5);
	c = b; // wipe out c, copy in b
  cout << c << '\n';
}
