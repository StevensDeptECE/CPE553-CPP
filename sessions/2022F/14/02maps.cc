#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main() {
  unordered_map<string, int> dict;
  dict["apple"] = 111;
  dict["bear"] = 209;
  dict["cat"] = 12;
  dict["acetyl"] = 4;

  unordered_map<string, double> stock = {
     {"AAPL", 146.25}, {"BIDU", 120.33}, {"MSFT", 240.44}
  };

    cout << stock["AAPL"] << '\n';
  for (const auto& s : stock) {
    cout << s.first << "-->" << s.second << '\n';
  }

// Don't do this!  cout << stock["QUARK"] << '\n';
//also not great! exception:    cout << stock.at("QuaRK");
    unordered_map<string,double>::iterator i = stock.find("Quark");
    if (i != stock.end()) {
     // i.first   i.second    
    }
    //double* p = stock.get("APPL")

   map<string, double> stock2 = {
     {"AAPL", 146.25}, {"BIDU", 120.33}, {"MSFT", 240.44}
   };

   for (const auto& s : stock2) {
    cout << s.first << "-->" << s.second << '\n';
   }

   stock2["x"] = 99;
   stock2["w"] = 102.8;
   for (const auto& s : stock2) {
    cout << s.first << "-->" << s.second << '\n';
   }

}