#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	//  key     value
	map<string, double> stockPrice;

	stockPrice["TSLA"] = 290;
	stockPrice["IBM"] = 132;
	stockPrice["MSFT"] = 73.5;
	stockPrice["AAPL"] = 205;
	
	cout << stockPrice["AAPL"] << "\n";
	cout << stockPrice["XXY"] << '\n';
#if 0
	string x = "xxx";
	char digits[10];

	for (int i = 1; i < 100000; i++) {
		string sym = x + std::to_string(i);
		if (stockPrice[sym] != 0) {
			cout << stockPrice[sym] << '\n';
		}
	}
#endif
	for (map<string, double>::iterator i = stockPrice.begin();
			 i != stockPrice.end(); ++i) {
		cout << i->first  << " ==> " << i->second << '\n';
	}

	for (auto x : stockPrice) {
		cout << x.first << " ==> " << x.second << '\n';
	}
	
	//	if (stockPrice.contains("XXY")) {
	//cout << stockPrice["XXY"]
	//	}
	
}
