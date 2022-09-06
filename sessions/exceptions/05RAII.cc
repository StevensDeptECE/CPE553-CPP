#include <iostream>
#include <unistd.h>
#include <fcntl.h>

template<size_t size>
class high_speed_stream {
private:
	int fh;
	char buf[size];
public:
	high_speed_stream(const char filename[]) {
		fh = open(filename, O_RDONLY);
		if (fh < 0) {
			throw "DIEDIEDIE";
		}
	}
	~high_speed_stream() {
		close(fh);
	}
};

int main() {
	/*old c:

		FILE * fp = fopen("myfile.dat", "w");
    fclose(fp); // REMEMBER THIS, or file does not fully write out
	*/

	//	ofstream f("file.dat"); // Resource Allocation Is Initialization

	try {
		high_speed_stream<8192> s("x.y");
    
		
	} catch(const char msg[]) {
		std::cerr << msg << '\n';
	}
	
}
