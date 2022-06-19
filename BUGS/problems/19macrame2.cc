#include <iostream>

#define f(a) a + a

int main() {
	int x = 0;
  int y =	f(x++); // x++ + x++
	std::cout << "x=" << x << " y=" << y;
}
	
