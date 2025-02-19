/**

The Babylonian algorithm to compute the square root of a positive number n is as follows:
1.	Make a guess at the answer (you can pick n/2 as your initial guess).
2.	Compute r = n / guess .
3.	Set guess= (guess + r) / 2.
4.	Go back to step 2 for as many iterations as necessary. The more steps 2 and 3 are repeated, the closer guess will become to the square root of n.
Write a program that inputs a double for n, iterates through the Babylonian algorithm until the guess subtract the previous guess smaller than 0.01, and outputs the answer as a double to two decimal places. Your answer should be accurate even for large values of n.

400.5
65189451651.5192165
1894651654984.11318

20.01
255322.25
1376463.46

 */

#include <iostream>

int main() {
    double n;
    while (std::cin >> n) {
        double guess = n / 2;
        double r = n / guess;
        guess = (guess + r) / 2;
        while (guess - r >= 0.01) {
            r = n / guess;
            guess = (guess + r) / 2;
        }
        std::cout << std::fixed;
        std::cout.precision(2);
        std::cout << guess << std::endl;
    }
    return 0;
}
