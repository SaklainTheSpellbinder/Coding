#include <stdio.h>
#include <assert.h>

int divide(int numerator, int denominator) {
    // Assert to ensure denominator is not zero
    assert(denominator != 0);

    return numerator / denominator;
}

int main() {
    int num = 10, denom = 0;

    // Will fail if denom is 0
    printf("Result: %d\n", divide(num, denom));

    return 0;
}
