#include <iostream>
using namespace std;
int main()
{
    std::cout << "Hello\n" << endl;

    int i ;
    while ( i < 10) {
        cout << i;
        i++;
    }
    // i = 10

    for (int i = 0; i < 10; i++) {
        cout << i;
    }

    cout << i << '\n';
    // the i in the for loop no longer exists
}
