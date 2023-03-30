#include <iostream>
#include <random>
using namespace std;
default_random_engine generator;

int main() {
    uniform_int_distribution<int> distribution(1,6);
    for (int i = 0; i < 10; i++) {
        int dice_roll = distribution(generator);  // generates number in the range 1..6 
        cout << dice_roll << '\n';
    }

    cout << "\n\n\nnow normally distributed\n";
    normal_distribution<double> N(0,1);
    for (int i = 0; i < 100; i++)
      cout << N(generator) << '\n';

}