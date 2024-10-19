#include<stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, a, b;
        long long profit = 0;  
        scanf("%d %d %d", &n, &a, &b);

        if (a >= b) {
            profit = (long long)a * n;
        } else {
            int units_with_decreasing_b = b - a;
            if (units_with_decreasing_b >= n) {
                profit = (long long)n * (2 * b - n + 1) / 2;
            } else {
                profit = (long long)units_with_decreasing_b * (2 * b - units_with_decreasing_b + 1) / 2;
                profit += (long long)(n - units_with_decreasing_b) * a;
            }
        }

        printf("%lld\n", profit);
    }

    return 0;
}
