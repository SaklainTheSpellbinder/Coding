#include<stdio.h>
int totalways(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n==3)
        return 4;
    return totalways(n-1)+totalways(n-2)+totalways(n-3);
}
int main(){
    int n;
    printf("Nuber of stairs: ");
    scanf("%d",&n);
    printf("The number of was is: %d",totalways(n));
    return 0;
}