/*
	classes may contain bitfields so you can allocate bits

 */

class A {
private:
	int x;
	bool y;
	int z:1; // bitfields
	int w:2;

};
