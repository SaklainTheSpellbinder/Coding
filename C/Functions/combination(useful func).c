#include<stdio.h>
int factorial(int a)
{
    int s=1;
    for(int i=1;i<=a;i++)
    {
        s=s*i;
    }
    return s;
}
int combination(int n, int r)
{ 
    int com=(factorial(n))/(factorial(r)*factorial(n-r));
    return com;
}
int main()
{
    int n,r;
    printf("Enter two numbers:");
    scanf("%d%d",&n,&r);
    printf("The combination:%d",combination(n,r));
    return 0;
}