#include "Account.hh"
#include <iostream>
using namespace std;

int main() {
	Account a("Dov", 10000000); //yay I'm rich!
	a.deposit(50);
	cout << a.getBalance() << '\n';
	while (a.withdraw(1000000)) {
		cout << "Successfully withdrew $1M!";
	}
}
