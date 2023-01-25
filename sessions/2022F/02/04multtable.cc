#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  const int n = 5;
  for(uint32_t i = 1; i <= n; i++){
    for(uint32_t j = 1; j <= n; j++)
      cout <<  setw(4) << i*j;
    cout << "\n";
  }




}