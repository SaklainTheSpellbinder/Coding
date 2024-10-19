#include<stdio.h>
int sum(int n){
    if(n==1)
    return 1;
    return n+sum(n-1);
}
int main()
{
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    int s=sum(a);
    printf("The sum is %d",s);
    return 0;
}