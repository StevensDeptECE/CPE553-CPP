#include <iostream>
#include <thread>
#include <mutex>
#include<unistd.h>
using namespace std;
mutex m;
int balance = 0;
void deposit(uint32_t n) {
	for (int i = 0; i < n; i++) {
		m.lock();
    //cout << "depositing " << flush;		
		balance++; // mov r0, balance; add r0, #1; str r0, balance
		m.unlock();
	}
}

void withdraw(uint32_t n) {
	for (int i = 0; i < n; i++) {
		m.lock();
		//cout << "withdrawing " << flush;		
		if (balance >= 1)
			balance--;
		m.unlock();
	}
}

int main() {
	const int n1 = 5;
	deposit(n1);
	cout << balance << '\n';
	withdraw(n1);
	cout << balance << '\n';

	constexpr int n = 10000000;
	thread t1(deposit, n);
	cout << "Immediately print balances: " << balance << '\n';
	//	usleep(1000);
	cout << "After a refreshing nap: " << balance << '\n';
	thread t2(withdraw, n);

	t1.join();
	t2.join();
	cout << balance << '\n';
}
	
