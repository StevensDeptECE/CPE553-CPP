void f(){
    int* p = new int[100];
}

int main() {
    for (int i = 0; i< 100000000; i++)
      f();
    uint64_t* a = new uint64_t[1000000]; // allocate 1million 8-byte integers
// if you lose a, you don't know where the memory is

    // memory leak

    delete [] a; // give the memory back

    int* b= new int[10];

    delete [] b;
    delete [] b; // illegal: cannot delete twice

    int*c = new int[10];
    c++; // point to the next memory location
    delete [] c; // illegal (crash)


    int* d = new int[100];
    d[100] = 99; // out of bounds, maybe ok?
    d[-1] = 1285189257;
    delete [] d; // illegal: You just claimed to return MUCH MORE MEMORY
    int a = 5;
    delete &a; // illegal, can only delete what was allcoated with new
}