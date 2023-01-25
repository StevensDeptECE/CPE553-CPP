#include <iostream>
using namespace std;

int main() {
    uint64_t a = 1000000 * 1000000;

    bool b = a == 1'000'000'000'000ULL;

    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < 1000; i++) {
        sum1 += .125;
        sum2 += .1; //    1/10 = 1/2 * 1/5
        //  .0001011011011
        // 1/10 = 1/16 + 1/64     
    }
    cout << "sum1 " << (sum1 - 125) << '\n'; 
    cout << "sum2 " << (sum2 - 100) << '\n'; 
//    bool sum1eq = sum1 == 1.25;
//    bool sum2eq = sum2 == 1.0;

    /*
        calculations are not exact (roundoff error)
        only if you are extremely lucky are they exact (powers of 2)
        NO: a + b + c == a + (b + c)


        YES: a + b == b + a
    
    */
   double x = .375 * 5; // exact! integer multiple of a POWER OF 2
   double y = .875; // exact
   double z = .975; // INEXACT 

 // if you calculate in decimal

    //.1011110101001010101
    // .123456

}