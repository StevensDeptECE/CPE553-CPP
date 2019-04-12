class Fraction {
private:
	int num, den;
public:
	Fraction(int n = 0, int d = 1) : num(n), den(d) {
		if (d == 0)
			throw "Div by zero";
			
	}
};

int main() {
	Fraction f1(1,2);
	Fraction f2(1,3);
	Fraction f3 = f1 + f2;

	Fraction f4(1,0);
}
