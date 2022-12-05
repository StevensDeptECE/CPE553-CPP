#include <iostream>
#include <unistd.h>
void leaky() {
    int* f = new int[500];
    for (int i = 0; i < 500; i++)
    f[i] = 0;

// this will stop the leak!    delete [] f;
}
int main() {
    for (int i = 0; i < 1000000; i++)
    leaky();
    sleep(50000);
}