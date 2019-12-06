#include <cstdint>
#include <string.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

class Image {
private:
  constexpr static uint32_t w = 400, h = 300;
  uint32_t pixels[h][w];
public:
  Image(uint32_t v) {
    for (uint32_t i = 0; i < h; i++)
      for (uint32_t j = 0; j < w; j++) {
        pixels[i][j] = v;
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
  Image im1(0xFFFF0000); // appears to be ABGR
  im1.save("blue.png"); // save our boring, solid black picture

  Image im2(0xFF00FF00); // appears to be ABGR
  im2.save("green.png"); // save our boring, solid black picture

  Image im3(0xFF0000FF); // appears to be ABGR
  im3.save("red.png"); // save our boring, solid black picture

	return 0;
}
