#include<stdio.h>
int totalways(int n)
{
    if(n==1 || n==2)
    return n;
    int ways=totalways(n-1)+totalways(n-2);
    return ways;
}
int main()
{
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    printf("The number of ways is:%d",totalways(a));
    return 0;
}