#include<stdio.h>
int totalways(int n){
    if(n==1 || n==2)
    return n;
    if(n==3)
    return 4;
    return totalways(n-1)+totalways(n-2)+totalways(n-3);
}
int main()
{
    int a;
    printf("Enter stair number:");
    scanf("%d",&a);
    printf("The number of ways:%d",totalways(a));
    return 0;
}