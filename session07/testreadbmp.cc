#include <iostream>
#include <fstream>

using namespace std;

#if 0
template<typename T>
void read(istream& f, T& val) {
	f.read((char*)&val, sizeof(T));
	// TODO: flip if bigendian
}										
#endif


void read(istream& f, uint32_t& val) {
	f.read((char*)&val, sizeof(int));
	// TODO: flip if bigendian
}										

void read(istream& f, uint16_t& val) {
	f.read((char*)&val, sizeof(uint16_t));
	// TODO: flip if bigendian
}										

class BMPHeader {
public:
	uint16_t type;
	uint32_t size;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t off_bits;
	uint32_t size2; // size of the data w * h * sizeperpixel
	uint32_t width;
	uint32_t height;
	uint16_t planes;
	uint16_t bitCount; // 24?
	uint32_t compression; // FALSE
	uint32_t imageSize; //???
	uint32_t xPixelsPerMeter;  // everything past here don't care...
	uint32_t yPixelsPerMeter;
	uint32_t clrUsed;
	uint32_t clrImportant;
public:
	BMPHeader(ifstream& f) {
		read(f, type);
		read(f, size);
		read(f, reserved1);
		read(f, reserved2);
		read(f, off_bits);
		read(f, size2); // size of the data w * h * sizeperpixel
		read(f, width);
		read(f, height);
		read(f, planes);
		read(f, bitCount); // 24?
		read(f, compression); // FALSE
		read(f, imageSize); //???
		read(f, xPixelsPerMeter);  // everything past here don't care...
		read(f, yPixelsPerMeter);
		read(f, clrUsed);
		read(f, clrImportant);
	}
	friend ostream& operator <<(ostream& s, const BMPHeader& b) {
		return s << b.type << ' ' <<
			b.size << ' ' <<
			b.reserved1 << ' ' <<
			b.reserved2 << ' ' <<
			b.off_bits << ' ' <<
			b.size2 << ' ' << // size of the data w * h * sizeperpixel
			b.width << ' ' <<
			b.height << ' ' <<
			b.planes << ' ' <<
			b.bitCount << ' ' << // 24?
			b.compression << ' ' << // FALSE
			b.imageSize << ' ' << //???
			b.xPixelsPerMeter << ' ' <<  // everything past here don't care...
			b.yPixelsPerMeter << ' ' <<
			b.clrUsed << ' ' <<
			b.clrImportant;
	}		
};

#if 0
class Bitmap {
private:
	int width, height;
	uint32_t* pixels;
};
#endif

int main() {
	ifstream f("red10x10.bmp", ios::binary);
	BMPHeader bh(f);
	cout << bh;
	cout << hex;
	const int width = 10, height = 10;
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			uint32_t color = 0;  //  R G B A    read as B G R
			f.read( ((char*)&color) + 1, 3);
			cout << color << ' ';
		}
		cout << "\n";
	}
}
		
