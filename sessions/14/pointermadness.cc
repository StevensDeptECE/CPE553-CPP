double (*p)(double x); // p is a pointer to functions that take one double paramter and returrn double


double integrate( double (*f)(double x), double a, double b, int n) {
	double x = a, const double dx = (b-a)/n;
	double sum = 0;
	for (int i = 0; i < n; i++, x += dx)
		sum += f(x);
  return sum * dx;
}

class A {
public:
	int f();
	int g();
	int h();

	void a(int x);
	void b(int y);
	void c(int z);
};


int main() {
	cout << integrate(sin, 0, 2*PI, 128) << '\n';
	A a1;
	cout << a1.f();
	a1.a();
	void  A::(*p)(int);
	p = A::a;
	a1.*p(2);
}
