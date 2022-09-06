#include <iostream>
using namespace std;

void print(const int x[], int len) {
    for (int i = 0; i < len; i++)
      cout << x[i] << ' ';
    cout << '\n';
}

void reverse(int x[], int len) {
    for (int i = 0; i < len/2; i++) {
        swap(x[i], x[len-1-i]);
    }
      
}

bool isPalindrome(const char x[], int len) {
    for (int i = 0; i < len/2; i++) {
        if (x[i] != x[len-1-i]){
            return false;
          }
    }
    return true;
}

//  5  4 3 2 1
int main() {
    int a[] = {5, 4, 3, 2, 1};
    reverse(a, 5); // reverse the elements
    print(a, 5); // print them out
    int b[] = {3, 9,7};
    print(b, 3);
    char s[] = "palindrome";
    cout << isPalindrome(s, sizeof(s)-1) << '\n';
    char s2[] = "atoyota";
    cout << isPalindrome(s2, sizeof(s2)-1) << '\n';
}