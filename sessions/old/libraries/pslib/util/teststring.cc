#include <iostream>
#include <sstream>
#include <ostream>
using namespace std;

main() {
#if 0
  string a;
  cout << "size of empty string: " << sizeof(a) << "\n";
  string s("testing");
  cout << "size of testing string: " << sizeof(s) << "len=" << s.length() << "\n";
  
  //  s += ' '; s += 1; s += 1.24;
  cout << s.length() << "\n";
  string s2 = "a";
  for (int i = 0; i < 10; i++) {
    s2 += s2;
  }
  for (int i = 0; i < 1000; i++)
    s += s2;

  cout << "final length=" << s.length() << "\n";
#endif

  string s("testing");
  string s2 = s;
  s2 += s2;
  cout << s2;
  enum { SIZE = 1024*1024 };
  string buf;
  ostrstream f(buf);
  for (int i = 0; i < 10; i++) {
    f << i << ' ';
  }
  cout << "\n" << buf << "\n";
  cout << buf.length() << "\n";
}
  
