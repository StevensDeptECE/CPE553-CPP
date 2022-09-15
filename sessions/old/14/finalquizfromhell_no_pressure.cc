int main() {
	int a; // auto variables (stack)
	const int* b;
	b = &a;
	int* const c = &a;
	*c = 99;
	class A {
	public:
		void f();
	} a0;
	A a1; // constructor? A::A()
	A a2();
	A* a3();
	A* a4 = new A();
	class B {
	public:
		int x,y,z;
	};
	int B::*mp;
	B b1;
	b1.x = 5;
	b1.y = 6;
	mp = &B::y;
	b1.*mp = 7;
	int& r = a;
	const int& r2 = a;
	int s = a++;
	s = ++a;
	cout << a;
	









	
