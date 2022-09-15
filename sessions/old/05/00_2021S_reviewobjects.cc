#include <iostream>
using namespace std;

class A { // A is a type of object

};

/*
	Some cats have fur and must implement the method meow()
  All dogs have fur and must implement the method bark()
  A mouse has fur.
  A fish has scales and implements swim()
 */
class Animal {
private:
	double weight;
public:
	Animal(double w) : weight(w) {}
	double getWeight() const { return weight; }
	//	virtual void eat() = 0;
};

// abstract class: a common parent for other classes
// if a class contains even 1 pure virtual function the class is abstract
class Mammal : public Animal {
private:
	int numChildren;
public:
	Mammal(double w, int numChildren) : Animal(w), numChildren(numChildren) {}
	virtual void emitSound() const = 0; // THERE IS NO CODE
	int getNumChildren() const { return numChildren; }
};


class Cat : public Mammal {
private:
  bool hasFur;
public:
	Cat() : Mammal(5.0, 0) {}
  void emitSound() const override {
		cout << "meow\n";
	}
};

class Dog : public Mammal {
private:
public:
	Dog(double w, int numChildren) : Mammal(w, numChildren) {}
	void emitSound() const override {
		cout << "woof\n";
	}
};

class Mouse : public Mammal {
	Mouse(double w, int numChildren) : Mammal(w, numChildren) {}
	void emitSound() const override {
		cout << "squeak\n";
	}
};

class Fish : public Animal {
public:
	Fish(double w) : Animal(w) {}
	void swim() {
		cout << "swim\n";
	}
};

int main() {
	// an object is an instance of a class
	A a1;   //a1 is an instance of A
	A a2; // instantiate a2 (create an instance)
	// A class is the type of an object
	// A class is the specification of an object
	///	Mammal m(3.5); ERROR: You cannot instantiate an abstract class
		
	Cat c;
	c.emitSound();
	cout << c.getNumChildren() << '\n';
	
	Dog d(10.5, 2);
	d.emitSound();
	cout << d.getNumChildren() << '\n';

	Mammal* m;
	m = &c; // A cat IS_A Mammal, so this works

	Mouse m1;
	// polymorphism
	m->emitSound();
	m =  &d;
	m->emitSound();
	m = &m1;
	m->emitSound();
	
	Mammal* list[3] = {&c, &d, &c};
	for (int i = 0; i < 3; i++)
		list[i]->emitSound();
	
	//	Cat* cp;
	//	cp = &d; // this makes no sense, a cat is not a dog
	
	Fish f(1.5);
	f.swim();
}
