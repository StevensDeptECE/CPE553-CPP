#include <memory.h>

int main() {
	int buf[1024] = {5, 1, 6};
	int buf2[1024];

	memcpy(buf2, buf, sizeof(buf));

}

 
