#include<stdio.h>
int main(){
    int base,power;
    scanf("%d%d",&base,&power);
    int product=base;
    for(int i=1;i<power;i++)
    {
        product*=base;
    }
    printf("%d",product);
    return 0;
}