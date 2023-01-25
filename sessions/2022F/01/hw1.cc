#include <iostream>
#include <cmath>
//complete the code above main


int main() {
    cout << sumSquaresUpTo(5) << '\n'; // inclusive: 1*1 + 2*2 + 3*3 + 4*4 + 5*5
    cout << sumSquaresUpTo(7) << '\n'; // inclusive: 1*1 + 2*2 + 3*3 + 4*4 + 5*5 +6*6 + 7*7
    float sum1;// compute the sum 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + ... + 1/100 =5.18....
    float sum2;// compute the sum 1/100 + 1/99 + 1/98 + ... + 1/1 = 5.18
    cout << sum1 << '\n';
    cout << sum2 << '\n';
    cout << (sum1 - sum2) << '\n';


    // mystery sum
    // be careful! if you calculate as int this will not work. use float!
    // be careful! overflow (i*i)
    // compute 1.0/(1*1) + 1.0/(2.0*2.0) + 1/(3*3) + ... + 1/(n*n)  n-> infinity
    float mystery1; //


    // compute  1/(n*n) + 1/((n-1)*(n-1)) +  1/((n-2)*(n-2)) + ...
    float mystery2; //

    // print out sqrt(mystery1*6).
    // print out sqrt(mystery2*6).


    cout << isPrime(81) << '\n'; // trial divide, 81%3 == 0 therefore not prime
    cout << isPrime(57) << '\n'; // 57 % 2, 57% 3, 57%4

}