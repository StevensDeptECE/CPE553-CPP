#include "Account.hh"

void Account::deposit(double amt) {
	balance += amt;
}

bool Account::withdraw(double amt) {
	if (amt > balance)
		return false;
	balance -= amt;
	return true;
}

double Account::getBalance() const {
	return balance;
}
