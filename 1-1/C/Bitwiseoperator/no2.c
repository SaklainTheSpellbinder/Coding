#include<stdio.h>
/*
void printBit(int x){
    int i, t;
    for (i = 1;i<=32;i++){
        t = x % 2;
        x = x / 2;
        printf("%d", t);

        if (i%8 == 0)
            printf(" ");
    }

    printf("\n");
}
*/

void printBit(int x){
    int i, t;
    for (i = 31; i >= 0; i--){
        printf("%d", x >> i & 1);

        if (i % 8 == 0)
            printf(" ");
    }

    printf("\n");
}

int setBit(int x, int p){
    return x | (1 << (p-1));
}

int resetBit(int x, int p){
    return x & ~(1 << (p-1));
}

int setBitRange(int x, int p, int n){
    return (1 << n) - 1 << (p-1) | x;
    //return (~(-1 << n) << (p-1)) | x;
    /*
    int mask;
    mask = -1;
    mask = mask << (32 - n);
    mask = (unsigned)mask >> (32-p-n+1);
    return mask | x;
    */
}

int resetBitRange(int x, int p, int n){
    return ~((1 << n) - 1 << (p-1)) & x;

    //return ~(~(-1 << n) << (p-1)) & x;
    /*
    int mask;
    mask = -1;
    mask = mask << (32 - n);
    mask = (unsigned)mask >> (32-p-n+1);
    return ~mask & x;
    */
}

int main(){

    int p = 4;
    int n = 4;
    int x = 456;

    /*
    printBit('a');
    printBit('A');

    printBit('z');
    printBit('Z');
    */

    char c = 'Z';
    printf("%c\n", c | (1<<5)); /// small letter
    printf("%c\n", c & ~(1<<5)); /// capital letter

    /*
    int even_bits = 0xAAAAAAAA & x;
    int odd_bits = 0x55555555 & x;
    printBit(((unsigned)even_bits >>1) | (odd_bits << 1));
    */

    return 0;
}