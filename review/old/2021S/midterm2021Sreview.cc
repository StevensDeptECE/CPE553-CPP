#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    You are not allowed to ask for help or share results with anyone else

    open book,  open notes, you may use your computer
    you can look on the internet, but you may not ask anyone else for help

    (I cannot ask you to tell me what a program does)

    1. Write code
    2. Fix my code
    3. Tell me what is wrong


    Covered on the midterm

    arithmetic (integer and floating point)
    floating point inf/nan
    casting and type promotion

    files
        cout << x << y;
        cin >> x >> y; // read in from keyboard

        ofstream f("myfile"); // opening a file for writing
        ifstream g("myfile"); // open a file for reading

        while (g >> x >> y) {

        }
				ifstream solar("solarsystem.dat");
				char buf[1024];
				solar.getline(buf, sizeof(buf))
				while (solar.getline(buf, sizeof(buf))) {
				  istringstream line(buf);
					line >> ....
				}

    loops and logic (while, for, if)
		  for (int i = 1; i < n; i *= 2)
       ;

			 while (true ) { // infinite loop

       }

			 for (int i = 0; ; i++) { / / infinite loop
			 }

			 for (;;) { // infinite loop

			 }

    functions
        calls
        recursion

    not reviewing, but everyone should know
        break
        continue
        switch
        goto

    ternary operator
      int max(int a, int b) { return  a > b ? a : b; }
      int min(int a, int b) { return  a < b ? a : b; }

			int min(int a, int b, int c) {
			  return a < b ? (a < c ? a : c) : (b < c ? b : c);
      }

			int min(int a, int b, int c) {
			  return min(min(a,b), c);
			}
  pointers
     p + 1
     p - 1
    operator ++, --   (pre and post inc/dec)
    rules of dynamic allocation
    new/delete
    malloc/free
  
default constructor

  classes
    public
    private
    constructor
    destructor
    copy constructor
    operator =
    move constructor

    operator overloading (friend, member, binary and unary)
		static functions

  inheritance
class A : public B { // A is a kind of B

  polymorphism

  vector<Vehicle*> vehicles;
  for (int i = 0; i < vehicles.size(); i++)
    vehicles[i]->payToll(); // looks at the object, follows the pointer, calls the appropriate function

  vector<>
  string
  random

    classes with dynamic memory
        constructor
        destructor
        copy constructor
        operator =  (old, and copy and swap)
        move constructor

*/
int max(int a, int b) {
    return a > b ? a : b;
#if 0
    if (a > b)
      return a;
    else
      return b;
#endif 
}

// templates NOT on midterm (final!!!)
template<typename T>
T mymin(T a, T b) {
    return a < b ? a : b;
}


mymin(3,4)
string a("hello"), b("bye");

mymin(a, b);

mymin("hello", "bye");


class A {
    A();
};


void example2() {
    int a[10] = {5, 3, 1, 4};
    int* p = a + 1; // p = &a[1]
    *p++ = 6;       // *p = 6 then p++   a[1] = 6, p = &a[2]
    *p-- = -2;      // a[2] = -2 then p = &a[1]
    *--p = 4;       // p = &a[0]    a[0] = 4
    ++*p;           //  a[0] = 5
    ++*++p;         //  p = &a[1]   a[1] = 7 
    // a[] = {}
}

void pointerloops() {
    int a[10];
    // write a loop with pointer to set a to zero
    for (int* p = a; p < a+10; p++)
      *p = 0;


    // write a loop with pointer to add 1 to every element
    for (int* p = a; p < a+10; p++)
      ++*p; // or (*p)++
}

void pointers() {
    int a[10] = {9, 1, 2};
    int* p = a;
    cout << *p << '\n'; // printed: 9
    p = &a[0]; // same thing as p=a
    cout << *p++ << '\n'; // print:  9  p points to &a[1]
    cout << (*p)++ << '\n'; // print 1  a[1] = 2  *p is an int   {9,2,2}
    cout << ++*p << '\n'; // a[1] = 3  print 3
    cout << *++p << '\n'; // p = &a[2]  print 2

    example2();
}

class Elephant {
private:
  string name;
public:
  // this is called the default constructor: 
  Elephant(const char name[]) : name(name) {} // if you write a constructor, the default no longer exists
	Elephant() : name() {} // if you write a constructor, the default no longer exists so write it!

  // ~Elephant() : ~name() {}
};

class X {
private:
    int count;
public:
// by default, the following functions are automatically generated if you don't
//  X() {}
//  ~X() {}
//  X(const X& orig) : count(orig.count) {}
    void f() const { cout << "f"; }
}

void rulesofDynamicMemoryAllocation() {
    int* p = new int; // if you allocate with new...
    delete p;

    p = new int[10]; // if you allocate an array of int...
    delete [] p; // implementation defined what happens if you forget [] but it will work

    Elephant* e = new Elephant[10]; // what is required to do this? (the default constructor)
    // WRONG: delete e; // only calls the destructor for the first element e[0]
    delete [] e; // calls the destructor 10 times

    p = new int[100];
    p++;

    delete [] p; // CRASH! you cannot give back different pointer

    p = new int[100];
    p[-1] = 5000000; // you cannot write outside the array safely
    delete [] p;      // CRASH! in this case most implementations will try to return more memory

    p = new int[10];
    delete [] p;
    delete [] p; // CRASH! cannot delete twice

    p = new int[10];

    // if you forget the delete, you leak the memory

    void* q = malloc(1024 * sizeof(int));
    free(q);

    e =  malloc(16 * sizeof(Elephant)); // does not call the constructor
    delete []e; // calls the destructor 16 times CRASH

    e = new Elephant[10]; // allocate 10 elephants and call Elephant::Elephant()
    free(e); // forget to call destructor, leak resources
}

/*
    operators  a+b a-b a*b a/b a%b
    a += b  a-=b  a*=b  a/= b a%= b
    -a
    +a
    cout << a;
    cin >> b;
    a.f() a.b
    a->b


    a *= 3 + 1   // this multiplies by 4!!! know order of ops

//  you cannot change the definition of any operator already defined
		int operator +(int a, int b) { return a -b; }


*/
class OperatorTest {
public:
// we will implement operator ++ using friend
 // OperatorTest a;
 // a++ (put a bogus parameter after to designate postincrement)
  friend void operator ++(OperatorTest& x, int) {// second parameter is BOGUS

  } 

  // ++a
  friend void operator ++(OperatorTest& x) { // unary!

  }

  // we will implement operator -- using members
  // a--
  void operator --(void*) { // first parameter is this second parameter is void*

  }
    // --a
  void operator --() { // first parameter is this

  }

// operator [] must be a member cannot be a friend
  int operator [](int x) const {
      return x+1;
  }
  int& operator [](int x) { // don't return something by reference that is going away! ERROR....
    return x; // this makes no sense here
  }

  string operator ()(int x, int y, float z) {
      return "yoho!";
  }
  

};

class Fraction  {
private:
    int num, den;
public:
    Fraction(int n, int d) {

    }
    friend ostream& operator <<(ostream& s, Fraction a) {
        return s << a.num << '/' << a.den;
    }

    friend istream& operator >>(istream& s, Fraction& a) { // friends do not have const after )
        char garbage;
        return s >> a.num >> garbage >> a.den;
    }
    // postincrement
    friend Fraction& operator ++(Fraction& a, char) {
        Fraction temp = a;
        a.num += a.den;
        return temp;
    }

    // preincrement
    friend Fraction& operator ++(Fraction& a) {
        a.num += a.den;
        return a;
    }
    // postdecrement
    Fraction& operator --(char) {
        Fraction temp = *this;
        num -= den; // this->num += this->den; is automatically understood
        return temp;
    }

    // predecrement
    Fraction& operator --() {
        num -= den;
        return *this;
    }
}

void overloading() {
  Fraction a(1,2);
  a++;
  ++a;
  Fraction b(1,3);
  a = b++;
  OperatorTest c;
  c[2] = 5;
  cout << c[3];
  cout << c(2, 3, 2.5f) << '\n';
}


void f(const int& x);

class Obj {
    public:
    void f() const; // this method f promises not to change this, in other words does not change the object
}

class Zebra {
private:
    int age;
public:
  // Zebra() {}
};

class DefJam {
public:
  DefJam(int x) {}
};

void defaultconstructor() {
  Zebra z;  
  // not legal: DefJam d;
  DefJam d(2);
  Zebra z2(); // this is NOT an object declaration because...
 
}


int main() {
    int ternary = 3 > 4 ? 5 : 6; // ternary = 6

    cout << mymin("abc", "bcd") << '\n'; // prints whichever pointer has the lower address (useless!)
    string a = "abc";
    string b = "def";
    cout << mymin(a,b) << '\n'; // 'a' < 'b' so this works

        //Q: which operators cannot be overloaded?     ::   .   sizeof  .*  ->*
    int a = 2;
    cout << a++ << '\n'; //postincrement. first use a, then add 1
    cout << ++a << '\n'; //preincrement.  first add 1, then use a
    pointers();
    overloading();
    defaultconstructor();
}







