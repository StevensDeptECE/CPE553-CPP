int main() {
    int a = 3;
    const int b = 4;
    const int*p = &a; // p can only look at the numbers
    cout << *p; // 3
    cout << p; // address of a

    a = 19;
    cout << *p; // 19
    p = &b;
    
    cout << *p; // 4 (p now points to b)
    int*const q = &a;
    *q = 23;

    const int* const r = &b; // r can only point to b
    // r


}