#include<stdio.h>
int main(){
    int low=3,high=6,n;
    n=high-low+1;
    unsigned int mask=~0;
    mask>>=(sizeof(unsigned int)*8-n);
    mask<<=low;
    for(int i=31;i>=0;i--){
        printf("%d",(mask>>i)&1);
    }
    return 0;
}