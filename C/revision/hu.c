#include <stdio.h>

int main() {
    int t = 13; // Number of test cases is fixed based on provided input
    long long x, y, k;

    // Array of inputs corresponding to the test cases
    long long inputs[13][3] = {
        {1, 3, 1},
        {2, 3, 1},
        {24, 5, 5},
        {16, 3, 2},
        {2, 2, 1},
        {1337, 18, 1},
        {1, 2, 144133},
        {12345678, 3, 10},
        {998244353, 2, 998244353},
        {998244353, 123456789, 998244352},
        {998244354, 998241111, 998244352},
        {998244355, 2, 9982443},
        {1000000000, 1000000000, 1000000000}
    };

    for (int j = 0; j < t; j++) {
        x = inputs[j][0];
        y = inputs[j][1];
        k = inputs[j][2];

        for (long long i = 1; i <= k; i++) {
            x++;
            while (x % y == 0) {
                x = x / y;
            }
        }
        
        printf("%lld\n", x); // Print the result for the current test case
    }

    return 0;
}
