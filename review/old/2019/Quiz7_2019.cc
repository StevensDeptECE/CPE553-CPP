class Bitmap {
private:
	uint32_t w, h;
	uint32_t* b;
public:
	Bitmap(uint32_t w, uint32_t h, uint32_t pixel)
		: w(w), h(h), b(new uint32_t[w*h])
	{
    for (uint32_t i = 0; i < w*h; i++)
			b[i] = pixel;
	}

	Bitmap() : w(0), h(0), b(nullptr) {}

	~Bitmap() {
		delete [] b;
	}

	Bitmap(const Bitmap& orig) :
		w(orig.w), h(orig.h), b(new uint32_t[orig.w*orig.h]) {
		memcpy(b, orig.b, sizeof(uint32_t) * w * h);
	}
#if 0
	Bitmap& operator =(const Bitmap& orig) {
		if (this != &orig) {
			delete [] b;
			w = orig.w;
			h = orig.h;
			b = new uint32_t[w*h];
			memcpy(b, orig.b, sizeof(uint32_t) * w * h);
		}
		return *this;
	}
#endif

	//modern approach: copy and swap
	Bitmap& operator =(Bitmap orig) {
		w = orig.w;
		h = orig.h;
		swap(b, orig.b);
		return *this;
	}
	Bitmap(Bitmap&& orig) : w(orig.w), h(orig.h), b(orig.b) {
		orig.b = nullptr;
	}
	
};

Bitmap makemeapicture() {
  Bitmap b(1024, 768, 0x0);
  return b;	
}

int main() {
	Bitmap b(100,200, 0xFF000000);
	Bitmap b2(b); //copy constructor
	Bitmap b3(150,100, 0xFFFF);
	b3 = b2;
	b3 = b3;
	b2 = b3 = b;
}
