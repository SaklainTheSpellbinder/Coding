#include<stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    int max, smax, tmax, qmax;

    // Find the maximum
    if (a >= b && a >= c && a >= d) {
        max = a;
    } else if (b >= a && b >= c && b >= d) {
        max = b;
    } else if (c >= a && c >= b && c >= d) {
        max = c;
    } else {
        max = d;
    }

    // Find the second maximum (excluding the maximum)
    if ((a >= b && a >= c && a >= d && a != max) || (b == max && a == max)) {
        smax = a;
    } else if ((b >= a && b >= c && b >= d && b != max) || (a == max && b == max)) {
        smax = b;
    } else if ((c >= a && c >= b && c >= d && c != max) || (a == max && c == max)) {
        smax = c;
    } else {
        smax = d;
    }

    // Find the third maximum (excluding the maximum and second maximum)
    if ((a >= b && a >= c && a >= d && a != max && a != smax) || (b == smax && a == smax)) {
        tmax = a;
    } else if ((b >= a && b >= c && b >= d && b != max && b != smax) || (a == smax && b == smax)) {
        tmax = b;
    } else if ((c >= a && c >= b && c >= d && c != max && c != smax) || (a == smax && c == smax)) {
        tmax = c;
    } else {
        tmax = d;
    }

    // The fourth maximum is the remaining number
    qmax = a + b + c + d - max - smax - tmax;

    printf("%d %d %d %d", qmax, tmax, smax, max);
    return 0;
}
