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
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    int nsp=n-1;
    int nsn=1;
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=nsp;k++)
        printf("  ");
        for(int j=1;j<=nsn;j++)
        {
            printf("%d   ",combination((i-1),(j-1)));
        }
        nsp--;
        nsn++;
        printf("\n");
    }
}