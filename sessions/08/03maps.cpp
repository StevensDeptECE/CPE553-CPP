#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
  map<string, double> quotes;
  quotes["IBM"] = 129.71;
  quotes["X"] = 26.11;
  quotes["XOM"]  = 108.96;
  quotes["AAPL"] = 160.77;

  double v = quotes["IBM"];
  cout << "IBM PRICE=" << v << '\n';
  v = quotes["Q"];
  cout <<"Q price=" << v << '\n';

  map<string,double>::iterator i = quotes.find("R");
  if (i == quotes.end()) {
    cout << "NOT THERE\n";
  } else {
    cout << i->second << '\n';
  }


  for (auto p : quotes) {
    cout << p.first << "==>" << p.second << '\n';
  }


    // hash maps are faster, but not sorted
    // hash maps keys are stored in unpredictable order that can change
    // without notice
  unordered_map<string, double> quotes2;
  quotes2["IBM"] = 129.71;
  quotes2["X"] = 26.11;
  quotes2["XOM"]  = 108.96;
  quotes2["AAPL"] = 160.77;

  v = quotes2["IBM"];
  cout << "IBM PRICE=" << v << '\n';

  unordered_map<string,double>::iterator j = quotes2.find("R");
  if (j == quotes2.end()) {
    cout << "NOT THERE\n";
  } else {
    cout << j->second << '\n';
  }

  for (auto p : quotes2) {
    cout << p.first << "==>" << p.second << '\n';
  }

}