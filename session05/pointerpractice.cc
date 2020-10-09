#include <iostream>
using namespace std;






void print(const int * x, int len){
    for(int i = 0; i < len; i++){ //loop for the whole array
        cout << *x << ", "; //print the element
        x+= 1; //increment the pointer to the next memory address
    }
    cout << endl; //print end line
}

void printReverse(const double* x, int len) {

    for (const double *p = x+len-1; p >= x; p--) {
        cout << *p << ", ";
    }
    cout << endl;
    // x += len-1;
    // for ( int i = 0; i < len; i++) {
    //     cout << *x << endl;
    //     x--; 
    // }
}

void zero(int x[], int length) {
    for (int *r = x; r < x + length; r++){
        *r = 0;
    }

}
int main() {
    int x[10];
    const int y[10] = {3, 4};
    print(x, 10); // print all the elements of x, promising not to change x

    zero(x, 10); // write zeros filling the array
    print(x, 10); // print and verify it's now zero

    print(y, 10);
    print(y, 2);
    print(y, 12); // ILLEGAL IMPLEMENTATION DEFINED WHAT HAPPENS. YOU COULD CRASH.

    double z[10] = {4.5, 2.8};
    print((int*)z, 10);
    printReverse(z, 10);

}