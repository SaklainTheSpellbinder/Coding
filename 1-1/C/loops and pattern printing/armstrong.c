#include<stdio.h>
int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    int sum=0;
    int y=n;
    while(y!=0)
    {
        int x=y%10;
        y=y/10;
        sum=sum+x*x*x;
    }
    if(sum==n)
    {
        printf("Armstrong Number");
    }
    else
    {
        printf("Not armstrong number");
    }
    return 0;
}