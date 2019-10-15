#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
  uint32_t sum = 0;
  for (int i = 1; i < argc; i++) {
    sum += atoi(argv[i]);
  }
  cout << "sum=" << sum << '\n';
}
  
  
