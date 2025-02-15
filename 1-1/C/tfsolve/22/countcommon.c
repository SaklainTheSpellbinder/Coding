#include<stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int mask=a^b;
    int count=0;
    while(mask){
        mask&=(mask-1);
        count++;
    }
    printf("common %d",32-count);
}