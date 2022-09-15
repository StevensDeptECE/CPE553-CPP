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
#pragma pack(2)
class BMPHeader {
public:
	uint16_t type;
	uint32_t size;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t headerSizeInBytes;
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
		f.read((char*)this, sizeof(BMPHeader));
#if 0
		read(f, type);
		read(f, size);
		read(f, reserved1);
		read(f, reserved2);
		read(f, headerSizeInBytes);
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
#endif
	}

	BMPHeader(uint32_t w, uint32_t h) {
		type = 0x4d42;
		const int bytesPerPixel = 3;
		size = 54 + w*h*bytesPerPixel;
		reserved1 = reserved2 = 0;
		headerSizeInBytes = 54;
		size2 = w*h*bytesPerPixel;
		width = w;
		height = h;
		planes = 1;
		bitCount = 24; // r,g,b are 1 byte each
		compression = 0; // no compression
		imageSize = size2;
		xPixelsPerMeter = 10000;
		yPixelsPerMeter = 10000;
		clrUsed = 0;
		clrImportant = 0;
	}
	void write(ostream& s) {
		s.write((char*)this, sizeof(BMPHeader));
	}
friend ostream& operator <<(ostream& s, const BMPHeader& b) {
		return s << b.type << ' ' <<
			b.size << ' ' <<
			b.reserved1 << ' ' <<
			b.reserved2 << ' ' <<
			b.headerSizeInBytes << ' ' <<
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
#pragma unpack

class Bitmap {
private:
	int width, height;
	uint32_t* pixels;
};

// this is currently failing.  It appears the picture is not a simple .bmp
void testRead() {
	ifstream f("red10x10.bmp", ios::binary);
	cout << "SIZEOF: " << sizeof(BMPHeader) << '\n';
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

void testWrite() {
	ofstream f("testwrite.bmp", ios::binary);
	BMPHeader bmp(20,10);
	bmp.write(f);
	const uint32_t pixel = 0xFF8000;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 10; j++)
			f.write((char*)&pixel, 3);
}

int main() {
	testWrite();
}
