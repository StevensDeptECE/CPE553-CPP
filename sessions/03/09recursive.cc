#include<iostream>
#include <cstdint>
using namespace std;

int fact(int n) {
    int prod = 1;
    for (int i = 1; i <= n; i++)
      prod *= i;
    return prod;
}

int fact2(int n) {
  if (n <= 1) {
    return 1;
  }

  return n*fact2(n-1);
}

// write recursive function count(n)
// count(0) = 0
// count(n+1) = 1 + count(n)

// 1 1 2 3 5 8 13 21 34 55 89 ...
double fibo(int n) {
    double a = 1, b = 1, c;
    // compute new c, advance a and b


   return c;
}

//recursively
double fibo2(int n) {
  if ( n <= 2) {
    return 1;
  }
  return fibo2(n-1) + fibo2(n-2);

}

// arrays are always passed by reference
// they are NOT COPIED!!!
void floodfill(uint32_t img[10][10], int r, int c,
 uint32_t border,uint32_t color) {
    if ( ) // base case
        return;

    // if not off edge, west
    // if not off edge, east
    // if not off edge, north
    // if not off edge, south

 }



int main() {
    int y = fact(5); // 5*4*3*2*1 = 120
    //cout << count(50000);
    for (int i = 10; i <= 50; i+= 10)
    cout << fibo2(i) << '\n';

    uint32_t a[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,0,0},
        {1,0,0,0,0,0,0,1,0,0},
        {1,0,0,0,0,0,0,1,0,0},
        {1,1,1,1,1,0,0,1,0,0},
        {0,0,0,0,1,0,0,1,0,0},
        {0,0,0,1,1,1,0,1,1,0},
        {0,0,0,1,0,0,0,0,1,0},
        {0,0,0,1,1,1,1,1,1,0}        
        };

    floodfill(a, 3, 4, 1, 2);     
/*
answer should look like:
    uint32_t a[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,0,0},
        {1,2,2,2,2,2,2,1,0,0},
        {1,2,2,2,2,2,2,1,0,0},
        {1,1,1,1,1,2,2,1,0,0},
        {0,0,0,0,1,2,2,1,0,0},
        {0,0,0,1,1,1,2,1,1,0},
        {0,0,0,1,2,2,2,2,1,0},
        {0,0,0,1,1,1,1,1,1,0}        
        };

}