#include <cstdint>
#include <string.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

class Image {
private:
	constexpr static uint32_t w = 400, h = 300;
  uint32_t pixels[w][h];
public:
  Image(uint32_t color) {
    for (uint32_t i = 0; i < h; i++)
      for (uint32_t j = 0; j < w; j++) {
        pixels[i][j] = color;
      }
  }
  void horizontalLine(int x1, int y, int x2, uint32_t color);
  void verticalLine(int y1, int x, int y2, uint32_t color);
  void save(const char filename[]) {
    stbi_write_png(filename, w, h, 4, pixels, w*4);
  }
};

  int main()
{
	/*
0    0000
1    0001
2    0010
3    0011
4    0100
5    0101
6    0110
7    0111
8    1000
9    1001
A    1010
B    1011
C    1100
D    1101
E    1110
F    1111
	 */

	// on an Intel processor, int is stored little-endian (low byte first)
  Image im1(0xFFFF0000); // appears to be RGBA
  im1.save("blue.png"); // save our boring, solid black picture

  Image im2(0xFF00FF00); // appears to be ABGR
  im2.save("green.png"); // save our boring, solid black picture

  Image im3(0xFF0000FF); // appears to be ABGR
  im3.save("red.png"); // save our boring, solid black picture

	return 0;
}
