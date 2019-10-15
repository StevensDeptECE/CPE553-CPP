#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <string>
#include <regex>
#include <random>

using namespace std;

/*
	This language checklist serves to let you know what you do and do
	not know about C++.  If you can predict what each of these functions
	does, that is a significant measure of your understanding of what
	C++ does, though it does not guarantee that you are able to create
	sequences of operations to do what you want, which is the other part
	of programming.

	Any function that covers a topic NOT required by the course is
	labelled as such. It may be a good idea to extend your knowledge
	before going for an interview at a high-powered C++ job, but it is
	not required for the final.
*/

void subject(const char name[]) {
	cout << "\n\n========================\n" << name << '\n';
}

void integeroperations() {
	subject("Integer Operations");
	int a = 2 / 3;         // integer division
	int b = 5 % 4 + 4 % 5 + 3 % 4 + 4 + 3;
	int c = 9 / 4;
	int d = a > 0 ? 6 : 4; // ternary operator
	double e = 1 / 2;

	cout << a << '\t'
			 <<	b << '\t'
			 <<	c << '\t'
			 <<	d << '\t'
			 <<	e << '\n';
}

void operatorprecedence() {
	subject("Operator Precedence");
	int a = 2 + 3 * 4;
	int b = 2 / 3 * 3;
	int c = (int)1.5 * 3;
	int d = 1 << 2 & 1 << 3;
	cout << a << '\t'
			 << b << '\t'
			 << c << '\t'
			 << d << '\n';
}

void equaloperatorprecedence() {
	subject("Equal Operator Precedence");
	int a = 3;
	int b = 4;
	int c = 5;
  a += b *= c -= 1;
	cout << a << '\t'
			 << b << '\t'
			 << c << '\n';
  a = b = c = 1;
  a *= 3 + 1;
	cout << a << '\t'
			 << b << '\t'
			 << c << '\n';
}

void overflow() {
	subject("Overflow");
	short a = 32767;
	a++;
	short b = -32767;
	b -= 3;
	int c = 1;
	for (int i = 0; i < 35; i++)
		c <<= 1;
	
	cout << a << '\t' << b << '\t' << c << '\n';
}

void typepromotion() {
	subject("Type Promotion");
	float a = 1.5f * 3;
	double b = 1 * 3;
	int c = 1.5f * 3;
	cout << a << '\t' << b << '\t' << c << '\n';
}

void roundoff() {
	subject("Roundoff");
	double x = sqrt(2);
	
	bool a = x*x == 2;
	bool b = x == x;
	cout << a << '\t' << b << '\n';
}

void nan() {
	subject("Inf and NaN");
	double a = 1.0 / 0.0;
	double b = -1.0 / 0.0;
	double c = 2.0 * a;
	double d = a + b;
	double e = 0.0 / 0.0;
	double f = sqrt(a);
	double g = sin(a);
	cout << a << '\t'
			 << b << '\t'
			 << c << '\t'
			 << d << '\t'
			 << e << '\t'
			 << f << '\t'
			 << g << '\n';
	cout << (e == e) << '\t' << (e != e) << '\t' << '\n';
}

void ifstatements() {
	subject("if Statements");
	int a = 1, b = 2;
	if (a < 2)
		cout << "A is less than 2\n";

	if (a < 1)
		cout << "A is less than 1\n";
	else
		cout << "A is NOT less than 1\n";

	if (a < b) {
		cout << "A is less than B\n";
	} else {
		cout << "A is NOT less than B\n";
	}

	if (a < b)
		if (a < 1)
			cout << "a < b and a < 1\n";
		else
			cout << "a < b and a is NOT < 1\n";
	else
		if (a < 1)
			cout << "a NOT < b and a < 1\n";
		else
			cout << "a NOT < b and a is NOT < 1\n";

	if (a < b) {
		if (a < 1)
			cout << "a < b and a < 1\n";
		else
			cout << "a < b and a is NOT < 1\n";
		cout << "this prints if a < b\n";
	}
}

void statements() {
	subject("Statements");
	int i = 10;
	while (i < 10) {
		cout << 'x';
	}
	cout << '\n';
	do {
		cout << 'y';
	} while (i < 10);
	cout << '\n';

	for (int i = 2; i < 12; i <<= 1)
		cout << i;
	cout << '\n';

	for (int i = 1; i < 16; i += 3) {
		if (i % 8 == 0)
			break;
		cout << i;
	}
	cout << '\n';

	for (int i = 0; i < 20; i += 4) {
		if (i % 16 == 12)
			break;
		if (i % 2 == 0)
			i++;
		cout << i;
	}
	cout << '\n';

	for (int i = 0; i < 10; i++) {
		if (i % 3 == 0)
			continue;
		cout << i;
	}

	for (int i = 0; i < 5; i++)
		switch(i) {
		case 0: cout << "zero";
		case 1: cout << "one";
		case 2: cout << "two";
		case 3: cout << "three";
		case 4: cout << "four";
		default: cout << "default";
		}
	cout << '\n';

	for (int i = 0; i < 5; i++)
		switch(i) {
		case 0:
			cout << "zero";
			break;
		case 1:
			cout << "one";
			break;
		case 2:
			cout << "two";
			break;
		case 3:
			cout << "three";
			break;
		case 4:
			cout << "four";
			break;
		default:
			cout << "default";
			break;
		}
	cout << '\n';
  // you should know the difference when not declaring the variable in the for loop

  int x;
  for (x = 0; x < 10; x++)
    cout << x << ' ';
  cout << '\n';
  cout << x << '\n'; // this would not be possible if x were declared in the loop
}

void thedreadedgoto(int n) {
	subject("The goto statement");
	// obviously, goto can be misused to create spaghetti code
	// There is only one decent use of goto in C++, shown below
	
	int countPrimes = 1; // special case for 2
	for (int i = 3; i <= n; i += 2) { // only odd numbers
		int lim = sqrt(i);
		for (int j = 3; j <= lim; j += 2)
			if (i % j == 0)
				goto notPrime; // goto in C++ is useful to jump out of loops
		countPrimes++; // if all divisors tested, must be prime!
	notPrime: // jump here to skip the prime count and keep going
		;
	}
	cout << "There are " << countPrimes << " primes up to " << n << '\n';
}

int x = 1;
namespace stevens {
	int x = 2;
}
void scopeandlifetime() {
	subject("Scope and Lifetime");
	int x = 3;
	cout << x++ << stevens::x++ << ::x++ << '\n';
	for (int i = 0; i < 2; i++) {
		int x = 0;
		static int y = 0;
		cout << x++ << y++ << stevens::x++ << ::x++ << '\n';
	}
}

void openingfiles() {
	subject("File I/O");
	{
		ofstream f("test.dat");
		f << "write to this file\n";
		f << 2 + 3 << '\n';
	}
	// at the end of the block, the destructor will fire
	// the file is automatically closed.
	ifstream f("test.dat");
	string s;
	f >> s; // reads in one word "write";
	getline(f, s); // read in the entire line "to this file"
	cout << s << '\n';
	int v;
	f >> v;
	cout << v + 1 << '\n';
}

void oldcstrings() {
	subject("Old (C) Strings");
	const char* s = "this is a constant string";
	// char* s2 = "this would not work, do you know why?";
	char s2[80] = "abc";
	strcat(s2, "def");
	cout << s2 << " length = " << strlen(s2) << '\n';
	// length of c strings is 1 longer then the length because they end with '\0'

	strcpy(s2, "xyz\n");

	/*
		you should know old fashioned printf.  In many ways better than new C++ stuff
		but not compile-time safe, uses runtime checking of the format string
	*/
	printf("%d %5.2lf, %.20lf %s\n", 52, 123.3456, 123.1234, "testing testing");
	//most important thing is to remember the extra '\0', huge source of trouble
	int v = atoi("283");
	cout << v << '\n';

	double d = strtod("1.234", nullptr);
	cout << d << '\n';
}

void cppstrings() {
	subject("New (C++) Strings");
	string a = "abc";
	a += "def"; // concatenation of strings
	cout << a << '\n';

	cout << "substring:" << a.substr(1) << '\n'; // starting with position 1
	cout << "substring:" << a.substr(1,2) << '\n'; // starting with 1, for length 2
	cout << "length:" << a.length() << '\n';
}

void identifiers() {
	subject("Rules for Identifiers (names of entities)");
	int thisIsALongVariableName = 1; // identifiers are names
	int abc123 = 2;
	int _donotusenames_startingwith_underscore = 3; // used by the compiler
	int __DONOT_USE = 4; // do not use names starting with two underscores, reserved to the standard
	const int CONSTANTS = 5; // C and C++ convention: constants are all caps

	// const variables have storage
	
	constexpr int BLACK = 0, WHITE = 1; // new C++11 way of specifying constants that have no storage, so better potential for optimization
	class A {}; // class names are identifiers
	void f(); // so are function prototypes
	
	// void g() { cout << "hello"; }  so are functions but I can't write one here
	// functions may not be declared within functions
}

namespace A {
	namespace B {
		class C {};
	}
};

// unlike anything else, namespaces may be declared multiple times.
// each one adds to the definition of the namespace.
// in this case, class D is added to namespace A::B
namespace A {
	namespace B {
		class D {};
	}
};

void namespaces() {
	subject("namespaces");
	A::B::C c1; // namespaces allow partitioning namespace to allow the same name to be used for multiple classes
	A::B::D d1;
}

void sizeofclasses() {
	subject("Size of classes (with bit fields)");
	class A{}; // minimum size of an object is 1, cannot be zero or two objects
	// could have the same address.
	// many c++ compilers would make this align with word width, for 64-bit computer=8
	cout << "Sizeof an empty class = " << sizeof(A) << '\n';

	class B {
		int a;
	};
	/*
		for an object containing 4-byte quantities, for speed C++ compilers 
		will usually align to 4-byte boundaries (at least)
		(if this object started at location 7, reading it would require two
		memory reads)
	*/

	cout << sizeof(B) << '\n';

	class C {
		double a;
		int b;
	};
	/*
		for an object containing an 8-byte entity like a double, it is faster to align
		to 8 bytes.  So even though this object only requires 12 bytes
		the compiler will take an extra 4 so that the result is a multiple of 8

		In this way, an array of these objects will have each element align to an 8-byte
		boundary for speed
	*/
	cout << sizeof(C) << '\n';

	class D1 {
		int a;
		double b;
		char c;
		double d;
		short e;
	};
	cout << "sizeof(D1)=" << sizeof(D1) << '\n';
	class D2 {
		double b;
		double d;
		char c;
		int a;
		short e;
	};
	// grouping fields to pack better is a big win
	cout << "sizeof(D2)=" << sizeof(D2) << '\n';

	class Bits {
		int a:2; // bit field: 2 bits (1 for sign, -2 .. +1)
		int b:3; // bit field: 3 bits (1 for sign, -4 .. +3)
		unsigned int c:5; // bit field: 5 bits (0 .. 31
	public:
		Bits(int a, int b, int c) : a(a), b(b), c(c) {}
	};
	Bits bits(-1, -3, 28);
	
	Bits bits2 = {-1,-3,28}; //  this only works in C++11 or better
	cout << "sizeof(Bits)=" << sizeof(Bits) << '\n';
}

void passArrayParameters(int a[], int n) {
  cout << "Sizeof array parameters is always = sizeof a pointer: " << sizeof(a) << '\n';
  cout << "The size of this array = " << n * sizeof(int) << '\n';
  a[2] = 9;
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
  cout << '\n';
}

void arrays() {
	subject("Arrays");
  int a[3] = {1, 2};
  passArrayParameters(a, 3);
	// size of an array parameter is the size of the pointer (8 bytes)
	cout << "sizeof array parameter is useless! = " << sizeof(a) << '\n';
	// always pass the size of the array manually with the array or make an object
	int b[4];
	cout << b[0] << ' ' << b[1] << ' ' << b[2] << ' ' << b[3] << '\n';
	// arrays are initialized with whatever is on the stack, random garbage!
	// to initialize
	int c[4] = {6, 5, 4}; // any remaining elements are initialized to zero
	for (int i = 0; i < 4; i++)
		cout << c[i] << ' ';
	cout << '\n';

	// declaration without size is possible if initialized
	int d[] = {7, 1, 2, 3};
	// note the loop: sizeof(d)/sizeof(int) computes the number of elements
	for (int i = 0; i < sizeof(d)/sizeof(int); i++)
		cout << d[i] << ' ';
	cout << '\n';
	
}

void func1(const char x[]) { // x is a readonly pointer to a, but cannot change, const char* const x;
	cout << x[2]; // array lookup
	cout << *(x+2); // pointer notation
}
void func2(const char* x) { // x is a pointer to a, cannot  change a, but can point somewhere else
	char foo[] = "test";
	x = foo;
	cout << x[2]; // array lookup
	cout << *(x+2); // pointer notation
}

void func3(const char* const x) { // exactly the same as func1
	cout << x[2]; // array lookup
	cout << *(x+2); // pointer notation
}

void arraypointerequivalence() {
	char a[] = "hello";
	func1(a);
	func2(a);
	func3(a);
}

void bitoperations() {
	subject("Bit operations");

	int a = 1 << 3; // 1 shifted left by 3, equivalent to 1 * 2 to the power 3 (8)
	int b = 48 >> 3; // 48 = 110000 in binary.  shift right by 3 = 1100 = 12
	// same as / 8
	int c = 0xF3AB & 0x2C39; // 1111 0011 1010 1011 BITWISE AND 0010 1100 0011 1001
	int d = 0xF3AB | 0x2C39; // bitwise OR
	int e = 0xF3AB ^ 0x2C39; // bitwise XOR
	int f = ~0xEDCAF3B2; // NOT
	int g = 0777; // leading zero is OCTAL (base 8), not decimal!!!
	cout << hex
			 << a << ' '
			 << b << ' '
			 << c << ' '
			 << d << ' '
			 << e << ' '
			 << f << '\n';
}

void regexexamples() {
	subject("regex");
	// this is obviously a huge topic not covered here.  this is a checklist
	// if you don't know regex, go back and learn it
	string s("this subject has a submarine as a subsequence");
  smatch m;
  regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

  cout << "Target sequence: " << s << '\n';
  while (regex_search (s,m,e)) {
    for (auto x:m)
			cout << x << " ";
    cout << '\n';
    s = m.suffix().str();
  }
}

void randomnumbergen() {
	subject("Random Number generators");
	// include <random>
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1,6);
	int diceRoll = distribution(generator);  // generates number in the range 1..6
	cout << diceRoll << '\n';

	normal_distribution<double> d2(5.0,2.0); // mean 5, variance 2

  for (int i=0; i < 10; ++i) {
    cout << d2(generator) << ' ';
  }
	cout << '\n';
}

void inheritance() {
	subject("inheritance");
	// this is not something you test at runtime.  Included here for your checklist
	// know what each of these means
	class A {};
	class B : public A {};
	// private A --> invisible in B
	// protected A --> protected in B
	// public A --> public B
	
	class C : private A {};
	// private A --> invisible in B
	// protected and public A --> private in B
  // "this is just for me" instead use: containment
	class Calternate {
	private:
		A a_internal;
	};
	
	class D : protected A {};
	// private A --> invisible in B
	// protected and public A --> private in B
  // "this is just for me and my children" instead use: containment
	class Dalternate {
	protected:
		A a_internal;
	};

	/*
		virtual inheritance is a fix for a problem involving multiple inheritance
	*/
	class Employee {
	private:
		string ssn;
	};
	class TempEmployee : public virtual Employee {
	};
	class Secretary : public virtual Employee {
	};
	/* were it not for virtual inheritance, this wacky construction would fail.
		 Really the problem is with multiple inheritance.
		 You should only inherit from one object, and promise to implement certain methods.
	 */
	class TempSecretary : public TempEmployee, public Secretary {
	};
};

void polymorphism() {
	
}

void templatefunctions() {

}

void templateclasses() {

}

void varargs() {
	subject("var args");
  // varargs are not typesafe.  You are just getting data off the stack
  printf("%d %d", 2);
}
/*
The syntax continues to get gnarlier...
*/
template<typename T>
T adder(T v) {
  return v;
}

template<typename T, typename... Args>
T adder(T first, Args... args) {
  return first + adder(args...);
}

//NOT needed for the course
void variadictemplates() {
	subject("Variadic Templates");
  //variadic templates are safe.  unlike varargs
  cout << adder(2,3) << '\n';
  cout << adder(2,3,4) << '\n';
  cout << adder(2,3,4.2) << '\n';
}

int main() {
	integeroperations();
	operatorprecedence();
  equaloperatorprecedence();
	overflow();
	roundoff();
	nan();
	ifstatements();
	statements();
	thedreadedgoto(100);
	scopeandlifetime();
	openingfiles();
	oldcstrings();
	cppstrings();
	namespaces();
	sizeofclasses();
	bitoperations();
	regexexamples();
	randomnumbergen();
	inheritance();
	polymorphism();
  varargs();
	templatefunctions();
	templateclasses();
	variadictemplates();
}
