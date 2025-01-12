#include<stdio.h>

union charToBinary{
    unsigned char n;
    struct{
        unsigned a: 1;
        unsigned b: 1;
        unsigned c: 1;
        unsigned d: 1;
        unsigned e: 1;
        unsigned f: 1;
        unsigned g: 1;
        unsigned h: 1;
    };
}x;

int main(){
    //ulta hoy bcz of little endian format 
    x.n='a';
    printf("%d%d%d%d%d%d%d%d",x.h,x.g,x.f,x.e,x.d,x.c,x.b,x.a);
}