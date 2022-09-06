#include <iostream>
using namespace std;
//a = { 5, 4, 1, 9, 8, 6, 3, 7, 2, 10};
// temp = a[0] = 5
// a[i] = a[9] = 10
//a = { 10, 4, 1, 9, 8, 6, 3, 7, 2, 10};
// a[n-i-1] = temp
void reverse(int a[], int n) { 
  for (int i = 0; i < n/2; i++) {
    int temp = a[i];
    a[i] = a[n - i - 1];
    a[n - i - 1] = temp;
  }
}

void print(const int a[], int n){
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
}

void printRev(const int a[], int n){
  for (int i = 0; i < n; i++) {
    cout << a[n-i-1] << ' ';
  }
}


int main() {
  int a[10] = { 5, 4, 1, 9, 8, 6, 3, 7, 2, 10};
  const int b[5] = {1, 2, 3, 4, 5};
  
  reverse(a, 10); // reverse the array in place
  print(a, 10); // print 10 2 7 3 6 8 9 1 4 5
  printRev(a, 10);

  // illegal, b can't change: reverse(b, 5);
  printRev(b, 5);
}