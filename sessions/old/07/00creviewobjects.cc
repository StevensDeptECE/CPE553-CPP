/*
	memory alignment issues
   0   1   2   3   4   5   6   7
0	[ ] [ ] [ ] [ ]	[ ] [ ] [ ] [ ]
8	[ ] [ ] [ ] [ ]	[ ] [ ] [ ] [ ]


*/

//sizeof(A) = 32 bytes

class A {
private:
	uint32_t a; // 4 bytes
 	uint8_t b; // 1 byte
	// insert 3 bytes of dead space
	double c;  // 8 bytes
	uint8_t d; // 1 byte
	// insert 7 bytes of dead space
	double e; // 8 bytes
public:
};

// write a class B to more efficiently pack
//sizeof(B) = 24 bytes
class B {
private:
	uint32_t a; // 4 bytes
 	uint8_t b; // 1 byte
	uint8_t d; // 1 byte
	// insert 3 bytes of dead space
	double c;  // 8 bytes
	double e; // 8 bytes
public:
