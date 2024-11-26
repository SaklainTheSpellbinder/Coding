#include<stdio.h>

int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);

    int max, smax, tmax, qmax;

    // First, assume that 'a' is the maximum
    max = a;

    // Check for maximum value
    if(b > max) max = b;
    if(c > max) max = c;
    if(d > max) max = d;

    // Now find the second maximum (excluding max)
    if(a != max) smax = a;
    else smax = b; // if a is max, assume b as second max candidate

    if(a != max && a > smax) smax = a;
    if(b != max && b > smax) smax = b;
    if(c != max && c > smax) smax = c;
    if(d != max && d > smax) smax = d;

    // Now find the third maximum (excluding max and smax)
    if(a != max && a != smax) tmax = a;
    else if(b != max && b != smax) tmax = b;
    else tmax = c; // assume c if both a and b are max and smax

    if(a != max && a != smax && a>tmax) tmax = a;
    if(b != max && b != smax && b > tmax) tmax = b;
    if(c != max && c != smax && c > tmax) tmax = c;
    if(d != max && d != smax && d > tmax) tmax = d;

    // The fourth maximum is the remaining number
    qmax = a + b + c + d - max - smax - tmax;

    printf("%d %d %d %d", qmax, tmax, smax, max);
    return 0;
}

