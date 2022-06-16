//#include <iostream>
//using namespace std;

unsigned int sum(unsigned int n) {
	unsigned int s;
	for (unsigned int i = n; i >= 0; --i)
		s += n;
	return s;
}

int main() {
	//	printf("%d", sum(5));
}

int* f() {
	int *a = new int(3);
	return a;
}

void g() {
  const	char msg[] = "CPE553!";
	const char* s = msg;
	while (*s != '\0')
		cout << *s++;
	cout << endl;
}
