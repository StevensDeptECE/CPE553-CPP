#include <iostream>
#include <time.h>
#include <sys/times.h>

using namespace std;

void f1(int n) {
	int* p = new int[n];
	for (int i = 0; i < n; i++)
		p[i] = i;
	delete [] p;
}

/*
	Rough benchmarking:

Method 1. measure elapsed time between two points of code using clock() call
Method 2. Measure elapsed time, user and system cpu time using the times()all
Note that for multiple CPUs, you are measuring CPU time not how much time it actually takes.
 */

typedef void (*FuncOneIntParam)(int n);

void benchmark(const char msg[], FuncOneIntParam f, int n) {
	clock_t t0 = clock();
	f(n);
	clock_t t1 = clock();
	cout << msg << " " << (t1-t0) << '\n';
}

void benchmark2(const char msg[], FuncOneIntParam f, int n) {
	struct tms start, end;
	clock_t t0 = times(&start);
	f(n);
	clock_t t1 = times(&end);

	clock_t userTime = end.tms_utime - start.tms_utime;
	clock_t sysTime = end.tms_stime - start.tms_stime;
	
	cout << msg << " clock:" << (t1-t0) << "\tuser:" <<
		userTime << "\tsystem:" << sysTime  << '\n';
}

int main() {
	for (int n = 1000000; n < 1000000000; n *= 10) {
		benchmark("memory write test", f1, n);
		benchmark2("memory write test", f1, n);
	}
}
