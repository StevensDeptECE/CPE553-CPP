#include <iostream>
#include <cstdint>
using namespace std;
int main()
{

  int x = 0;
  while (x < 10)
  {
    cout << x; //0123456789
    x = x + 1; // x += 1; x++; ++x;
  }

  int count = 1;
  while (count <= 10)
  {
    cout << count; //12345678910
    count++;
  }
  cout << "at the end, count = " << count << '\n';

  int y = 0;
  while (y < 10)
    cout << y++ << endl;

  int y2 = 0;
  while (y2 < 10)
    cout << ++y2 << endl;

  int z = 10;
  while (z < 10)
  {
    cout << z;
    z++;
  }

  int w = 0;
  while (w < 10)
    cout << ++w; //12345678910
}
