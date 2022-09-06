#include <iostream>

int y = 17;
static int x = 6;

void f() {
	int a = 3;
  static int y = 1;
  cout << y << '\n';
  y++;
  cout << x << '\n';
}
