#include <iostream>

#define f(a) a++
#define g(a) x3?!
int main() {
	std::cout << f(3) << '\n';
	int x = g(2); // why is this line wrong? Doesn't it look perfect?
}
	
