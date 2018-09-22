class Trace {
private:
  string name;
public:
	Trace(string functionName) : name(functionName) {
		cout << "Entering function " << name << '\n';
	}
  ~Trace() {
		cout << "Leaving function " << name << '\n';
	}
};

void g() {
	Trace t("g");   //"Entering function g .....   leaving function g"
	cout << "a";
}

void f() {
	Trace t("f");   //"Entering function f .....   leaving function f"
	cout << "b";
	g();
	cout << "c";
}

int main() {
	cout << "d";
	f();
	cout << "e";
}
