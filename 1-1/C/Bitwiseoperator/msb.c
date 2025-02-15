#include<stdio.h>
int main(){
    int n;
    n=55;
    int msb=0;
    while(n){
        msb=n&1;
        n>>=1;
    }
    printf("%d",msb);
}