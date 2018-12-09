#pragma once

#include <string>
class Account {
private:
	std::string name;
	double balance;
public:
	Account(const std::string& name, double initialBalance) :
		name(name), balance(initialBalance) {}
	void deposit(double amt);
	bool withdraw(double amt);
	double getBalance() const;
};
