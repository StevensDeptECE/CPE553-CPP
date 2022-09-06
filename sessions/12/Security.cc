#include <map>
using namespace std;
/**
	 For details of basic finance see: http://..... page 110
	 
	 
	 @author: Dov Kruger
 */



/*
	A security is financial instrument, something that can be bought and
	sold on a market.

	Every security must have a price, and a yield.  The yield may be zero
 */
class Security {
private:
	static int count;
  static	map<string, Security*> ticker; // Security::ticker
  double price;
  string sym;
public:
  Security(double price, const string& sym) : price(price), sym(sym) {
		count++;
		ticker[sym] = this;
	}
	double getPrice() const { return price; }

	static Security* find(const string& sym) {
		map<string, Security*>::iterator i = ticker.find(sym);
		if (i == ticker.end())
			return nullptr;
		return i->second;
	}
	virtual	double yield() = 0;
};
int Security::count = 0;
map<string, Security*> Security::ticker;

class Stock : public Security {
private:
	double _dividend;
public:
	Stock(double price, const string& sym, double dividend)
		: Security(price, sym), _dividend(divididend) {}
	double dividend() { return _dividend ; }
	double yield() { return dividend() / price; } 
};

class Bond {
public:
	double coupon() {}
	double couponPayment() {}
	yield()
};

class Position {

	quantity,   Security*

};


class BrokerageAccount {
private:
	vector< Position > portfolio;
	double balance;
public:
  BrokerageAccount(double money);
	void deposit(double amt);
	bool withdraw(double amt); // return false if it doesn't work
	void buy(const string& sym, int qty);
	void sell(const string& sym, int qty); // can't sell what you don't own
};





int main() {
	new Security(175.6, "AAPL");
	new Security(170, "BIDU");
	Security* s = Security::find("AAPL");

}
