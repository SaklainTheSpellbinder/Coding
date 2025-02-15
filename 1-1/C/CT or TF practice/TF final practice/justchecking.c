#include <stdio.h>
#include <math.h>

int main() {
    float inf = 1.0 / 0.0;   // Positive infinity
    float ninf = -1.0 / 0.0; // Negative infinity
    float nanVal = 0.0 / 0.0; // NaN (undefined operation)

    printf("Inf: %f, -Inf: %f, NaN: %f\n", inf, ninf, nanVal);
}
