#include <stdio.h>
long long calculate_final_value(long long x, long long y, long long k) {
    if (y == 1) {
        return x + k;
    }
    long long increment_count = 0;
    while (k > 0) {
        x++;
        k--;
        while (x % y == 0) {
            x /= y;
        }
        if (x < y) {
            increment_count += k;
            x += k;
            k = 0;
        }
    }
    return x;
}
int main() {
    int test_cases;
    scanf("%d", &test_cases);

    while (test_cases--) {
        long long x, y, k;
        scanf("%lld %lld %lld", &x, &y, &k);
        printf("%lld\n", calculate_final_value(x, y, k));
    }

    return 0;
}
