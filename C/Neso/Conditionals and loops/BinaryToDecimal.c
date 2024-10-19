#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    printf("Enter binary number:");
    scanf("%d",&a);
    int r,sum=0,count=0;
    while(a!=0)
    {
        r=a%10;
        a/=10;
        sum=sum+r*pow(2,count);
        count++;
    }
    printf("The decimal is %d",sum);
    return 0;
}