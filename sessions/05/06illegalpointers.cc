int main() {
    const int a; // can't declare a const without a value
    const int b = 3;
    int* p = &b; // illegal: b cannot change, and p is threatening
    const int* q = b; // illegal: only valid in embedded systems with meaningful location #3
    // also on intel pointers are 64 bits, int is 32 bits (wrong size)
    
    int c = 42;
    int d = 2;
    int* const x = &c; // legal
    // x cannot change what it points to
    x = &d; //therefore, this is illegal
    *x = 40; // you can write to the value, but not change x
}