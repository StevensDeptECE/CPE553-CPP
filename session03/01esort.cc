#include <iostream>
using namespace std;
void sort(int x[], int len) {
  for (int j = 0; j < len-1; j++)
    for (int i = 0; i < len-1; i++)
      if (x[i] > x[i+1]) {
        int temp = x[i];
        x[i] = x[i+1];
        x[i+1] = temp;
      }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sort2(int x[], int len) {
  for (int j = 0; j < len-1; j++)
    for (int i = 0; i < len-1; i++)
      if (x[i] > x[i+1]) {
          swap(x[i], x[i+1]);
      }
}

int main() {
    int a[] = {5, 8, 4, 7, 6, 9, 1};
    sort(a, sizeof(a)/sizeof(int) );
    for (int i = 0; i < sizeof(a)/sizeof(int); i++)
      cout << a[i] <<  ' ';
    cout << '\n';
    int b[] = {3, 5, 8, 4, 7, 6, 5, 9, 1};
    sort(b, sizeof(b)/sizeof(int) );
    for (int i = 0; i < sizeof(b)/sizeof(int); i++)
      cout << b[i] <<  ' ';
    cout << '\n';


}