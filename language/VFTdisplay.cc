#include <cstdint>
using namespace std;

// $ g++ -g -Wno-pmf-conversions test.cc && ./a.exe
#include <stdio.h>
class Vehicle {
public:
	virtual void print() const = 0;
	virtual void payToll() const = 0;
	virtual void fn3() const = 0;
	virtual void fn4() const = 0;
};

class Car : public Vehicle {
public:
	int val;
	bool expensive;
	int price;
	long long something;
	Car() : val(5), expensive(true), price(65535), something(0x0123456789ABCDEFLL) {
	}
	void print() const override {
	}
	void payToll() const override {
	}
	void fn3() const override {
	}
	void fn4() const override {
	}
};

class Truck : public Vehicle {
public:
	double w;
	Truck() : w(10000) {}
	void print() const override {
		printf("I'm a truck!\n");
	}
	void payToll() const override {
	}
	void fn3() const override {
	}
	void fn4() const override {
	}
};


void raw_dump(const void *ptr, int len) {
	int i, j;
	int ptr_size;
	char ascii[17] = {0};
	ascii[16] = '\0';

	// calculate printed pointer size
	for (i = 7; i >= 0; --i) {
		if ((uint64_t)ptr & (0xFFLL << (i * 8))) {
			ptr_size = i + 1;
			break;
		}
	}

	// header
	printf("% *c",ptr_size * 2 + 3, ' ');
	for (i = 0; i < 16; ++i) {
		if (i == 8)
			printf(" ");
		printf("%02X ", i);
	}
	printf("\n%*─────────────────────────────────────────────────┼─────────────────\n", ptr_size * 2 + 4);

	for (i = 0; i < len; ++i) {
		// address
		if (i % 16 == 0)
			printf("0x%0*lx ", ptr_size * 2, (uint64_t)ptr + i);
		
		// byte
		uint8_t byte = ((uint8_t*)ptr)[i];
		printf("%02X ", byte);
		// get ascii repr
		if (byte <= 0x1F || (byte >= 0x7F && byte <= 0xA0) || byte == 0xAD)
			ascii[i % 16] = '.';
		else
			ascii[i % 16] = byte;
		
		// space at 8
		if (i % 16 == 7)
			printf(" ");
		
		// pad out last bytes
		if (i + 1 == len && i % 16 != 15) {
			ascii[(i + 1) % 16] = '\0';
			for (j = (i + 1) % 16; j < 16; ++j) {
				printf("   ");
				if (j % 16 == 7)
					printf(" ");
			}
		}

		// ascii at 16
		if (i % 16 == 15 || i + 1 == len) {
			printf("│ %s", ascii);
			printf("\n");
		}
	}
	printf("\n");
}

int main() {
    Car c;
    Truck t;

		printf("sizeof(Car)= %ld\n", sizeof(Car));
		printf("sizeof(Car)= %ld\n", sizeof(c));
		printf("sizeof(Truck)= %ld\n", sizeof(Truck));
		
    printf("dump 48 bytes from c\n");
    raw_dump(&c, sizeof(c)*3/2);

    printf("\tc.vptr = %p\n", *(void**)&c);
    printf("\tc.val = 0x%x\n", c.val);
    printf("\tc.expensive = 0x%x\n", c.expensive);
    printf("\tc.price = 0x%x\n", c.price);
    printf("\tc.something = 0x%llx\n\n", c.something);

    printf("dump 40 bytes from vtable for Car\n");
    raw_dump(*(void**)&c, sizeof(c)*3/2);

    printf("\n");
		
		c.print(); // compiler can (with optimization) literally do NOTHING
    auto print = &Car::print;
    auto payToll = &Car::payToll;
    auto fn3 = &Car::fn3;
    auto fn4 = &Car::fn4;
    printf("Address of Car::print(): %p\n", (void*)(c.*print));
    printf("Address of Car::payToll(): %p\n", (void*)(c.*payToll));
		printf("Address of Car::fn3(): %p\n", (void*)(c.*fn3));
		printf("Address of Car::fn4(): %p\n", (void*)(c.*fn4));

    printf("dump 24 bytes from t\n");
    raw_dump(&t, sizeof(t)*3/2);
		
		printf("dump 40 bytes from vtable for Truck\n");
    raw_dump(*(void**)&t, sizeof(c)*3/2);

    auto tprint = &Truck::print;
    auto tpayToll = &Truck::payToll;
    printf("Address of Truck::print(): %p\n", (void*)(t.*tprint));
    printf("Address of Truck::payToll(): %p\n", (void*)(t.*tpayToll));
}
