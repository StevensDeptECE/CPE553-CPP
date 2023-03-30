#include <cstdio>
#include <iostream>

using namespace std;
#if 0
int setvbuf(
   FILE *stream,
   char *buffer,
   int mode,
   size_t size 
);
#endif

int main() {
  setvbuf(stdin, (char *)NULL, _IONBF, 0); //unbuffered stdin
	int c;

	while (c = getc(stdin)) {
		cout << c;
	}
}
