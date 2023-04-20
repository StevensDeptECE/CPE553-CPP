/*
  You have to write:
  1. Constructor (that allocates dynamic memory)
  2. Destructor (free the memory delete [])
  3. Copy Constructor
  4. Operator = (use either old way or copy and swap)
  5. Move Constructor
  6. write image: see https://github.com/memononen/nanosvg/blob/master/example/example2.c
 */
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

class DynamicBitmap {
private:
	uint32_t* p;
	uint32_t w, h;
// your class goes here!

public:
	// constructor, destructor, copy constructor, operator =, move constructorr
	uint32_t operator ()(int y, int x) const {
    return p[y * w + x];
	}

	uint32_t& operator ()(int y, int x) {
    return p[y * w + x];
	}
	//https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
	void line(uint32_t x1, uint32_t y1,
						uint32_t x2, uint32_t y2, uint32_t color) {
		int x = x1, y = y1;

		//		set(x,y, RED);
		(*this) (x,y) = color;
	}

#if 0
	//+50% if you do this :https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
	void wuline(uint32_t x1, uint32_t y1,
						uint32_t x2, uint32_t y2, uint32_t color) {
		int x = x1, y = y1; // go to it!

		(*this) (x,y) = color;
	}
#endif
};

DynamicBitmap makemeone(int w, int h) {
	DynamicBitmap x(w, h, RED);
	return;
}

int main() {
	// FIRST PART (ADD COLORS HERE)
	constexpr uint32_t BLACK = 0xFF000000; // black opaque
	constexpr uint32_t RED = 0xFFFF0000; // red opaque
	constexpr uint32_t GREEN = 0xFF00FF00; // red opaque
	constexpr uint32_t DARK_GREEN = 0xFF008000; // red opaque
	
	
	// SECOND PART (DO NOT EDIT)
	int xcenter = 100;
	int ycenter = 100;
	int xdiameter = 200;
	int ydiameter = 100;

	DynamicBitmap b(1024, 1024, BLACK); // Potentially dynamic size (Now: 1024 x 1024 pixels)
	b(32,32) = RED;
	cout << b(32,32);
	
	b.horizLine(0, 500, 200, RED); // Red horizontal line, from x=0 to x=500, at y = 200
	b.vertLine(0, 399, 300, RED); // Red vertical line, from y=0 to y=399, at x = 300
	
	b.drawRect(200,200, 100,50, BLUE); // Blue rectangle, TOP-LEFT at x=200, y=200. width=100, height=50
	b.fillRect(201,201, 98,48, WHITE); // White rectangle, same rules as above, but filled with color
	
	b.line(400,0, 550,300, YELLOW); // Line drawn using https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
	
	//	b.wuline(400,100, 550,400, GREEN);  //optional
	
	b.save("bitmap2.png");
	DynamicBitmap b2 = b; // test copy constructor
	b2 = b; // test operator =
	b2.save("bitmap2copy.png");
	DynamicBitmap b3 = makemeone(50,80);
	b3.save("moved.png");
}

