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

}

int resetBitRange(int x, int p, int n){

}

int main(){

    printBit(-1);


    int p = 4;
    int x = 10;
/*
    printBit(1);
    printBit(1 << (p-1));
    printBit(x);
    printBit(setBit(x, p));
*/
    printBit(1);
    printBit(1 << (p-1));
    printBit(~(1 << (p-1)));
    printBit(x);
    printBit(resetBit(x, p));

    //printf("%d", x >> (n-1) & 1);
    /*
    int y = x >> 1;
    int z = x << 1;

    printf("x >> 1 = %d, x << 1 = %d\n", y, z);
    */



    ///printBit(x);

    return 0;
}