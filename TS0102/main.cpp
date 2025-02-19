/**

Given a integer A as a time in seconds. Convert the format of A from (seconds) to (hours: minutes: seconds).

For each test case, input a integer A(0 <= A <= 2^64-1). Stop until read an EOF.


For each test case, print "x hours y minutes and z seconds", the value of x, y, z is described above.


50391
489123456786
569035139015

13 hours 59 minutes and 51 seconds
135867626 hours 53 minutes and 6 seconds
158065316 hours 23 minutes and 35 seconds
 */

#include <iostream>

int main() {
    uint64_t input;
    while (std::cin >> input) {
        const uint64_t hours = input / 3600;
        const uint64_t minutes = (input % 3600) / 60;
        const uint64_t seconds = input % 60;

        std::cout << hours << " hours " << minutes << " minutes and " << seconds << " seconds" << std::endl;
    }
    return 0;
}
