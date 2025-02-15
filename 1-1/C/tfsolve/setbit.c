#include<stdio.h>
void printbinary(long long int x){
    if(x>>1!=0){
        printbinary(x>>1);
    }
    printf("%lld",x&1);
}
int setBitsY(int x, int p, int n,int y){
    int m = ~(~0<<n);
    int z = m & y;
    z <<= p-n+1;
    m <<=p-n+1;
    m = ~m;
    return (m & x | z);
}
int main(){
    printbinary(100000000000);
    printf("\n");
    printbinary(5475);
    printf("\n");
    printbinary(setBitsY(65489,12,6,5475));
}