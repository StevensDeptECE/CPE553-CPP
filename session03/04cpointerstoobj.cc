class Thingy {
public:
	int x;
	double y;
};

int main() {
	int a = 2;
	int * p = &a; // p points to a

	*p = 5; // a = 5
	Thingy t = {5, 2.2};
	Thingy* s = &t;
	s->x = 3;

	(*s).x = 4; // same as ->
}
	
