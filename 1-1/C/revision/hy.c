#include <stdio.h>

long long calculate_final_value(long long x, long long y, long long k) {
    while (k > 0) {
        x++;
        k--;
        while (x % y == 0) {
            x /= y;
        }
        // Early termination if `x` is less than `y`
        if (x < y) {
            x += k;
            break;
        }
    }
    return x;
}

int main() {
    int test_cases = 13;
    long long test_data[13][3] = {
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

    for (int i = 0; i < test_cases; i++) {
        long long x = test_data[i][0];
        long long y = test_data[i][1];
        long long k = test_data[i][2];
        printf("%lld\n", calculate_final_value(x, y, k));
    }

    return 0;
}

