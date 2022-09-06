#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

	unordered_map<string, double> stockPrice;

	stockPrice["TSLA"] = 290;
	stockPrice["IBM"] = 132;
	stockPrice["MSFT"] = 73.5;
	stockPrice["AAPL"] = 205;

	cout << stockPrice["XXY"] << '\n';
	
	for (unordered_map<string, double>::iterator i = stockPrice.begin();
			 i != stockPrice.end(); ++i) {
		cout << i->first  << " ==> " << i->second << '\n';
	}
	cout << "\n\n";
	for (auto x : stockPrice) {
		cout << x.first << " ==> " << x.second << '\n';
	}
	cout << "\n\n";
	
}
