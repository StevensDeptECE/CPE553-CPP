class List {
private:
	int used;
	int capacity;
	int* data;
public:
};

int main() {
	List a;
	List a(1000);
	for (int i = 0; i < 10; i++)
		a.add(i);

	List d;
	List b = a; // copy
	List c(a); // copy
  c = d;
	
