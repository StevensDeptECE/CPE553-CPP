#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Account {
private:
	double balance;
	mutex m;
public:
	Account() : balance(0) {}

	void deposit(double amt) {
		m.lock();
    balance += amt;
		m.unlock();
	}
	bool withdraw(double amt) {
		m.lock();
		if (balance < amt) {
			m.unlock();
			return false;
		}
		balance -= amt;   //  load R0, balance load R1, amt SUB R0,R1 store R0, Balance
		m.unlock();
		return true;
	}
	double getBalance() const { return balance; }
};

Account  a;
const int n = 1000000;

void deposits() {
	for (int i = 0; i < n; i++)
		a.deposit(1);
	cout << a.getBalance() << '\n';
}

void withdrawals() {
	for (int i = 0; i < n; i++)
		a.withdraw(1);
	cout << a.getBalance() << '\n';
}

int main() {

	thread t1(deposits);
	thread t2(withdrawals);
	t1.join();
	t2.join();
	return 0;
}

	
