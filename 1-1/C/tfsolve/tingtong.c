#include<stdio.h>
int main(){
    int a = 8, b, *pa, *pb;
float x = 0.001, y = 0.2, *px = &x, *py = &y;

pb = &a;
b = *pb + 7;
pa = pb;
*px *= *pa + *pb;
*py += *pa;

printf("%x %x %d %.2f", pa + 2, &(*pa), a, x);

}