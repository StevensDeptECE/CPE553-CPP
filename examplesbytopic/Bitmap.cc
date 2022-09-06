class Bitmap {
private:
	int rows, int cols;
	uint32_t* pixels;
public:



	Bitmap(uint32_t rows, uint32_t cols) : rows(rows), cols(cols), data(new int[rows*cols]) {
		

	}

	uint32_t operator ()(int r, int c) const {
		return data[r * cols + c ];
	}
	uint32_t& operator ()(int r, int c) {
		return data[r * cols + c ];
	}
};
