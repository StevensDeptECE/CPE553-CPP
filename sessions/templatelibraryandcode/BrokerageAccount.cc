#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

unordered_map<string,double> quotes;

class BrokerageAccount {
private:
	double                      balance;
  unordered_map<string,int>   positions;
  string                      custName;
public:
  BrokerageAccount(const char name[]) : custName(name), balance(0) {}
	void deposit(double amt) {
		balance += amt;
	}

	void buy(int qty, const char symbol[]) {
		unordered_map<string,double>::iterator i = quotes.find(symbol);
		if (i == quotes.end()) {
			cerr << "No such symbol!";
			return;
		}
		double cost = qty * i->second;
		if (cost > balance) {
			cerr << "You can't afford it! Bring more money!\n";
			return;
		}
		balance -= cost;
		positions[symbol] += qty;
	}
	friend ostream & operator <<(ostream& s, const BrokerageAccount& b) {
		for (const auto& p : b.positions)
			cout << p.first << "\t==>\t" << p.second << '\n';
		return s;
	}
};

class Bank {
private:
	unordered_map<uint64_t, BrokerageAccount*> accounts;
public:
	Bank() {}
	void createAccount(const char name[], uint64_t ssn) {
		accounts[ssn] = new BrokerageAccount(name);
	}
};

int main() {
	quotes["AAPL"]=132.32;
	quotes["IBM"]=133;
	
	BrokerageAccount a("Dov");
	a.deposit(1000000);
	a.buy(1000, "AAPL");
	a.buy(100, "IBM");
	a.buy(100, "AAPL");
	cout << a;
}
