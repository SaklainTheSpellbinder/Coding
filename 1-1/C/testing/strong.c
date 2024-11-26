#include<stdio.h>
int factorial(int n)
{
    if(n==1)
        return 1;
    else
        return n*factorial(n-1);
}

int main(){
    int n,r;
    scanf("%d",&n);
    int real=n;
    int sum=0;
    while(n)
    {
        r=n%10;
        sum+=factorial(r);
        n/=10;
    }
    if(real==sum)
        printf("Strong");
    else
        printf("Ghuma bae");
    return 0;
}