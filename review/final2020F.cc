/*
data types (int, long, short, uint32_t, uint64_t, int32_t, ... float, double
 bool, char)
*/


int main() {
	const int x = 1;
	const long y = 123456789012345L;
	const unsigned long long y = 123456789012345ULL;

	uint64_t a = 1234ULL;


	// know rules of floating point
	//IEEE754
	// float = 7 digits
	// double = 15 digits
	// long double is not standard
	// there is quad precision

	// inf and nan
	// never write: if (a == b) for float
	//	if (abs(a-b)<eps)

	// loops

	//arrays
	//multidimensional arrays

	int a[10][3] = {
									{1, 2, 3},
									{4, 1},
									

	};

	// packing of struct/class
	/*
     0  1  2  3  4  5  6  7
0    x           y  y  y  y
8    z
16   w  w  w  w  w  w  w  w
24   q                    
32


	 */
	class A{
		char x;
		uint32_t y;
		char z;
		double w;
		char q;
	};

	class B {
		char x;
		char z;
		char q;
		uint32_t y;
		double w;
	};
	cout << 	sizeof(B);
	cout << sizeof(A);

	class A {
	private:
		int x;
	public:
		A(int x) {}
		A() {}
		~A() {}
		
	};

	//	What are the defaults generated for a class?

	class X : A{
	private:
		int a,b;
	public:
    X():A() {}
		~X() : ~A() {}
		X(const X& orig) : A(orig), a(orig.a), b(orig.b) {}
		// operator=?
	};

	class Z {};
	Z z1;
	Z z2(); // this is not an object it's a function!

	class C {
	public:
		virtual void f();     // virtual
		virtual void g() = 0; // pure virtual, cannot instantiate C
		//general rule: if you write even one virtual function, implement virtual destructor
		virtual ~C(); // see: Scott Meyers, effective C++
	};

	
	//
  class D: public C {
	public:
		void g() override;  // write the code overriding the parent pure virtual
		// so that you can instantiate D
	};
	C* p = new D();
		p->f(); // will call the right one using the VFT
		p = new E();

		delete p; // if p is pointing to E, then call E::~E(), if p is pointing to D, call D::~D()



		void D::g() { // know how to write the function outside the class to implement g()

		}


		// Dynamic memory

		// new vs. delete
		// new X[10] vs. delete []
		// malloc() vs. free()

		//		dynamic memory inside class
		// constructor, destructor, copy constructor, operator =, move constructor

		Exception handling

			try {

			} catch(Ex& e) {

			} catch (const char* msg) {

			} catch (...) {

			}

		void f() throw() { // this functions throws nothing. If it does you will crash
		}

		void g() throw (OutOfBounds) { // this function only throws named exception
		}

		
		/*
			bit operations
			AND &,  OR |, XOR ^, NOT ~
			<<  >>
		*/

		uint32_t set(uint32_t val, uint32_t bitsToSet) {
			return val | bitsToSet;
		}

		void clear(uint32_t v, uint32_t pos) {
			v &= ~(1 << pos);
		}
