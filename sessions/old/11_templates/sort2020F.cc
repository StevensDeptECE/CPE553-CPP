#include <iostream>
using namespace std;

template<typename T>
T sort(T x[], int len) { //O(n^2)            //type unification T=int
    for (int i = 0; i < len-1; i++) {   //O(n)
        for (int j = 0; j < len-1; j++) // O(n)
          if (x[j] > x[j+1]) {
              T temp = x[j];
              x[j] = x[j+1];
              x[j+1] = temp;
          }
    }
    return x[len-1];
}

template<typename T>
void print(const T x[], int n) {
  for (int i = 0; i < n; i++)
    cout << x[i] << " ";
  cout << '\n';
}


int main() {
    int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1};
//    { 8, 7, 6, 5, 4, 3, 2, 1, 9};
//    { 7, 6, 5, 4, 3, 2, 1, 8, 9};
    sort(a, sizeof(a)/sizeof(int));
    print(a, sizeof(a)/sizeof(int));
    int b[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 2, 1, 4};
    sort(b, sizeof(b)/sizeof(int));
    print(b, sizeof(b)/sizeof(int));

    double c[] = {2.5, 1.0, 3.2, 1.7};
    sort(c, sizeof(c)/sizeof(double));
    print(c, sizeof(c)/sizeof(double));
    string s[] = {"hello", "ahoy", "abacus", "ohayoo", "fred"};
    sort(s, sizeof(s)/sizeof(string));
    print(s, sizeof(s)/sizeof(string));
    cout << sizeof(string) << '\n';
}