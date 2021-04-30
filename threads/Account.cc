#include <iostream>
#include <iomanip>
#include <thread>
using namespace std;

class Account {
private:
	double balance;
public:
	Account() : balance(0) {}
	void deposit(double amt) { balance += amt; }
	bool withdraw(double amt) {
		if (balance > amt) {
			balance -= amt;
			return true;
		}
		return false;
	}
	double getBalance() const {
		return balance;
	}
};

void deposits(Account* a, int n) {
	for (int i = 0; i < 2*n; i++)
		a->deposit(1);
}

void withdrawals(Account* a, int n) {
	for (int i = 0; i < n; i++)
		a->withdraw(1);
}
	
void singleThreaded(Account* a, int n) {
	for (int i = 0; i < 2*n; i++)
		a->deposit(1);
	for (int i = 0; i < n; i++)
		a->withdraw(1);

}

int main() {
  Account a;
	const int n = 100000000;
	//	singleThreaded(&a, n);
	//#if 0
	thread t1(deposits, &a, n);
	thread t2(withdrawals, &a, n);
	t1.join();
	t2.join();
	//	#endif
	cout << setprecision(15) << a.getBalance() << '\n';
}

	
