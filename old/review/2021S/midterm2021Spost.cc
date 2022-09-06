
class SolarSystem;

class Body {
private:
	SolarSystem* containedBy;
	
};
class SolarSystem {
	vector<Body> bodies;
};

extern int x;
void f(); // function prototype
extern void f(); // function prototype

int main() {
	f();
	return 0;
}

void f() {
	cout << "hello\n";
}

