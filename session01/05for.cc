#include <iostream>
#include <cstdint>
using namespace std;
int main()
{
  for (int i = 1; i < 10; i++)
  {
    cout << i;
    cout << "yo";
  }
  cout << '\n';
  for (int i = 1; i <= 10; i++)
    cout << i;
  cout << '\n';
  for (int i = 1; i > 10; i++)
    cout << i;
  cout << '\n';
  for (int i = 1; i <= 10; i--)
    cout << i;
  cout << '\n';
  for (int i = 1; i <= 100; i = i * 2) // 1248163264
    cout << i;
  cout << '\n';
}
