#include <flif.h>
#include <iostream>
#include <iomanip>

using namespace std;

#pragma pack(push,1)
typedef struct RGBA
{
  uint8_t r,g,b,a;
} RGBA;
#pragma pack(pop)

ostream & operator <<(ostream& s, RGBA rgba) {
	return s << rgba.r << rgba.g << rgba.b << rgba.a;
}
void loadFlif(const char filename[]) {
	FLIF_DECODER* d = flif_create_decoder();
  if (d == nullptr)
		throw "Can't allocate memory";
	flif_decoder_set_quality(d, 100); //lossless
	flif_decoder_set_scale(d, 1);
	if (!flif_decoder_decode_file(d, filename)) {
		//TODO:		delete??? d
		throw "can't decode file";
	}
	FLIF_IMAGE* img = flif_decoder_get_image(d, 0);
	if(img == nullptr) {
		//delete d;
    //TODO: check bow to undo		
		throw "no decoded image";
	}
#if 0
	void* blob = nullptr;
	size_t blob_size = 0;
	if(!flif_decoder_decode_memory(d, blob, blob_size)) {
		//TODO delete d
		//TODO delete decoded
		throw "decoding memory failed";
	}

	FLIF_INFO* info = flif_read_info_from_memory(blob, blob_size);
	if (info == nullptr) {
		//TODO: delete d
		//TODO: delete decoded
		//TODO: delete blob
		throw "read pixels failed";
	}
#endif
	int w = flif_image_get_width(img);
	int h = flif_image_get_height(img);
	int channels = flif_image_get_nb_channels(img);
	//	int depth = flif_info_get_depth(img);
	//	int n = flif_info_num_images(img);

	RGBA* b = new RGBA[w * h];
	for (int y = 0, c = 0; y < h; y++, c += w) {
		flif_image_read_row_RGBA8(img, y, b+c, w * sizeof(RGBA));
		cout << hex;
		for (int i = 0; i < w; i++) {
			cout << b[c+i] << ' ';
		}
	}
	
	delete [] b;
	flif_destroy_image(img);
	//	flif_free_memory(blob);
	flif_destroy_decoder(d);
}


int main(int argc, char** argv) {
	loadFlif("test.flif");
}
