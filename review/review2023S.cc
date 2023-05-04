template<typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}


void bitoperations() {
    int a = 3, b = 5, c= 11;

    int d = a & b; // bitwise AND   0011
                //                  0101
                //                  0001 = 1
    int e = a | b; // bitwise OR    0011
                //                  0101
                //                  0111 = 7
    int f = a ^ b; // xOR           0011
                //                  0101
                //                  0110 = 6
    int g = ~a; //          111111111100
    int h = 1 << 3;         //     00001
                            //     01000   (same as * 2**3)
                               64+16+8+3
    int i = 91 >> 4;        //  1011011 >> 4 = 101 = 5
    a <<= 2; // 3 = 011  left shift by 2 01100 

    uint32_t x = 0x30000006; // 0011 0000 0000 0000 0000 0000 0000 0110

     // 10000000000000000000000000110000
     // 00000000000000000000000000000001  OR
     // 10000000000000000000000000110001
     x = (x << 3) | (x >> 29); // rol #3, %rcx

 }

class Employee {
private:
    uint64_t ssn;
};

class Temp : public virtual Employee {
private:
  Date exp;
};

class Secretary : public virtual Employee {
public:
  void type();
};



