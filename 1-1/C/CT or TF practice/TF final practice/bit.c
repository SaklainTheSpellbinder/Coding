#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        unsigned int x;
        scanf("%u",&x);
        unsigned int y;
        unsigned int mask1=(x&(-x));
        unsigned int mask2=((~x)&(-(~x)));
        if(mask1==x){
            y=mask1|mask2;
        }
        else{
            y=mask1;
        }
        printf("%u\n",y);
    }
    return 0;
}