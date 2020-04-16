#include <iostream>
#include <thread>
#include <mutex>
#include<unistd.h>
using namespace std;

int balance = 0;
mutex m;
void deposit(uint32_t n) {
	for (int i = 0; i < n; i++) {
		
		balance++; // mov r0, balance; add r0, #1; str r0, balance
	}
}

void withdraw(uint32_t n) {
	for (int i = 0; i < n; i++)
		if (balance > 1)
			balance--;
}

int main() {
	deposit(10000);
	cout << balance << '\n';
	withdraw(10000);
	cout << balance << '\n';

	thread t1(deposit, 100000000);
	usleep(1000);
	thread t2(deposit, 100000000);

	t1.join();
	t2.join();
	cout << balance << '\n';
}
	
