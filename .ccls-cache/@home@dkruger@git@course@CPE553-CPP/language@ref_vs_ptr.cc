struct A{
    uint8_t a;
    uint32_t c : 15;
    uint32_t d : 1, e: 3;
    uint64_t b;

};
int main() {
    int a;
    int b;
    int * p = &a;
    *p = 9;
    p = nullptr; // pointers may point at nothing

    p++; // pointer arithmetic (bad with variable!)

    p = new int[10000];
    int* q = p + 3; // only use address arithmetic in a block you know. Don't go out of bounds, or else

    A arr[10];

}
