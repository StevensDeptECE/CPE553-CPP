#include <iostream>
#include <cmath>

#define ARRAYSIZE 3

using namespace std;

void add(const double a[ARRAYSIZE][ARRAYSIZE], const double b[ARRAYSIZE][ARRAYSIZE], double c[ARRAYSIZE][ARRAYSIZE]){
  for (uint32_t i = 0; i < ARRAYSIZE; i++){
    for (uint32_t j = 0; j < ARRAYSIZE; j++){
      c[i][j] = a[i][j] + b[i][j];
    }
  }
} 

void print(const double a[ARRAYSIZE][ARRAYSIZE]){
    for (int i = 0; i < ARRAYSIZE; i++)
      for (int j = 0; j < ARRAYSIZE; j++) {
        cout << a[i][j] << " ";
      }
}

int main() {
  const double a[ARRAYSIZE][ARRAYSIZE] = {
    {1, 2, 3}, 
    {4, 5, 6},
    {7, 8, 9}
  };
  const double b[ARRAYSIZE][ARRAYSIZE] = {
    {1, 2, 3}, 
    {4, 5, 6},
    {7, 8, 9}
  };

  double c[ARRAYSIZE][ARRAYSIZE];
  add(a, b, c);
  print(c);
  print(c);
}