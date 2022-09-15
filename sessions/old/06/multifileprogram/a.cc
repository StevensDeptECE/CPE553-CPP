#include <iostream>
int x = 191;

void f() {
	static int count = 0;
	count++;
	std::cout << "hello" << count << '\n';
}
