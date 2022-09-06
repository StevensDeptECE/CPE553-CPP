#include "StringBuffer.hh"

int main() {
  enum { SIZE = 1024*1024 };
  String s("testing");
  String s2 = s;
  s2 += s2;
  cout << s2;
  cout << s;
  //#if 0
  StringBuffer buf(SIZE);
#if 0
  buf.append('a').append("testing\n").append(3).append('\n');
  buf.append(4.2).append("\n");
#endif
  cout << buf;

  for (int i = 0; i < 10000; i++)
    buf.append(i).append(' ');
  //#endif
}
