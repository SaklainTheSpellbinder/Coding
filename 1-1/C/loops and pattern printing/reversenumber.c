#include<stdio.h>
int main()
{
    long int a=0,p,n;
    printf("Enter the number:");
    scanf("%ld",&n);
    while(n!=0)
    {
        p=n%10;
        n=n/10;
        a=a*10+p;
    }
    printf("The reverse number:%ld",a);
    return 0;
}
