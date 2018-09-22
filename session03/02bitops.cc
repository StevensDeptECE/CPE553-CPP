#include <iostream>
using namespace std;

int main() {
	int a = 11;    // 0001011
	int b = 6;     // 0000110
	int c = a & b; // 0000010 = 2  AND
	int d = a | b; // 0001111 = 15  OR
	int e = a ^ b; // 0001101 = 13 XOR
	int f = ~a;    // 111111111111111110100 = 2s complement -12???

	//shifting

	int g = 1 << 5; // 000000000100000 multiply by 2**5 = 32
	int h = 1024 >> 3; // 00000010000000  1024 / 2**3 = 1024/8 = 128
	int i = 55 >> 3; // 55  =  0000110111 = 32+16+4+2+1  55>>3 = 55/8 = 0110 = 6


}
