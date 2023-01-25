#include <regex>
#include <iostream>
#include <string>
using namespace std;
int main() {
  const char s[] = "this is a test. this is a long string. Testing testing 123";

  regex pat("test");

  const char* p = s;
  cmatch m;

  while (regex_search(p, m, pat)) {
    cout << m.position(0) << "," << m.length(0) << '\n';
    p += m.position(0) + m.length(0);    
  }
}