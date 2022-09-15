
class LinkedList {
private:
	class Node { // LinkedList::Node
	public:
		int val;
		Node* next;
	};
	Node* head;
public:
	LinkedList() {}
	~LinkedList() {
		// delete each pointer, but be VERY CAREFUL
		// first get the next pointer, THEN DELETE THIS ONE!!!
	}
	// optional: 150% for writing
	// old c++: linker error if called 	LinkedList(const LinkedList& orig) ;

	// new C++11 way
	LinkedList(const LinkedList& orig)  = delete;
	LinkedList& operator =(const LinkedList& orig)  = delete;

	// move constructor
	LinkedList(LinkedList&& orig) { // steal orig data while it's dying (nice)

	}
};
/**
  head --> nullptr

  head --> [ val=3 next= nullptr  ]

  head -->  [val=1 next= ---->  [ val=3 next= nullptr  ]



 */
int main() {
	LinkedList a; // create an empty list  (head == nullptr
	a.addStart(3); // 3 is the first element in the list
	a.addStart(1); // 1  3
	a.addStart(4); // 4 1 3
	cout << a << '\n'; // print out the list
	//	LinkedList b = a; // GIVES A LINKER ERROR BECAUSE YOU DIDN'T IMPLEMENT COPY CONSTRUCTOR

}
