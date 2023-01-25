#include <iostream>
using namespace std;

int* f() {
    int a = 19;
    int x[10];
    int* p = &a;
    return p;
}
//old c pointers
int main() {
    int a = 3;
    int *p = &a; // p points to a  (makes optimization worse)

    a = 4;
    *p = 5;

    cout << a << '\n';
    int* badptr = f();    
    int* q = (int*)malloc(1024*sizeof(int));

    free(q);
}