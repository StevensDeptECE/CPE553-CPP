#include <iostream>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int main() {
    constexpr int SIZE = 2048;
    int x[SIZE] = { 1, 257};
    int fh = open("test.dat", O_WRONLY|O_BINARY);
    if (fh < 0) {
        std::cerr << "error can't open file\n";
        exit(-1);
    }
    const int n = 20'000;
    for (int i = 0; i < n; i++)
        write(fh, (char*)x, SIZE * sizeof(int));

    close(fh);
}