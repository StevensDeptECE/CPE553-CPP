class A {
private:
	int x; // only you can see this. Only entities defined within the bounds of this class
	// can see this symbol
protected:
	int y; // you can see it, or your children can see it
public:
	void f();
  friend void g();
	friend MyFriendClass;
};


// this is what Java does
class B : public A { // IS_A
	// whatever is private in the parent is INVISIBLE TO me.
	// whatever is protected in the parent is protected to me
	// whatever is public in the parent, is public for me.
};


class C : private A {
	// whatever is private in the parent is INVISIBLE TO me.
	// whatever is protected or public in the parent is PRIVATE

};

A* ap = new C(); // NO inheritance is private

class C {
private:
	A impl;

	//impl.f();
};


class D : protected A {
	// whatever is private in the parent is INVISIBLE TO me.
	// whatever is protected or public in the parent is PROTECTED
	// that means it's only for me and my descendents
};

class D {
protected:
	A impl;

};
