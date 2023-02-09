int main() {
    int a = 3;
    int b = 4;

    int*p = // p is a pointer to int
    
     &a; // &a give me the address of a in memory
     *p = 88; // a just changed
     cout << a << '\n';
    p = &b;
    cout << *p << '\n';
    const int*q = &a; // q is a pointer to const int
    a = 22;
    cout << *q << '\n';
    //*q = 44; // NO
    q = &b; // now point to b
    *p = 55;
    cout << *q;
    int* const r = &a;
    *r = 23;
    //r = &b;
    const int* const s = &a;
}