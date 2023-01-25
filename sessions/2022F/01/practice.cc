#include <iostream>

int main()
{
  /*
    char            8                                   'x'
    short int       <= int                              2h
    int             >= 16 bits and <= long int          3
    long int        <= long long int                    3L
    long long int                                       3LL

    unsigned int
    signed int

  */

  uint8_t a = 100 + 200;
  std::cout << (int)a << std::endl;

  uint32_t b = 1000000 * 1000000;
  std::cout << b << std::endl;

  uint64_t c = 1000000LL * 1000000LL;
  std::cout << c << std::endl;
  uint64_t d = 1000000;
  d = d * 1000000;
  std::cout << d << std::endl;

  uint32_t age;
  std::cin >> age;
  age = age * 365 * 24 * 60 * 60;
  std::cout << age << std::endl;
  return 0;
}