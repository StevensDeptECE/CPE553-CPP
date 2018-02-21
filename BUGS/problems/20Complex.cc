class Complex {
private:
	double x,y;
public:
	Complex() : x(0), y(0) {}
	Complex(double x = 0, double y = 0) : x(x), y(y) {}
};

int main() {
	Complex c1(1.5,0);
	Complex c2();
	Complex c3;
}
