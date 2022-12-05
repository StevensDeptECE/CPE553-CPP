#include <iostream>
#include <unistd.h>
#include <sys/ptrace.h>

using namespace std;
int main() {
	int pid = getpid();
	long status = ptrace(PTRACE_TRACEME, pid, nullptr, nullptr);
  sleep(6000);
  int a = 3;
	uint64_t b = 123;
	float f = 1.2;
	double d = 2.5;
	cout << a << b << f << d;
  return 0;
}
		
