#include<stdio.h>
int main()
{
    int i=1,n,a=10;
    printf("Enter the Number:");
    scanf("%d",&n);
    while(i>=1)
    {
        if(n%a==n)
        {
            printf("The Number of digits:%d",i);
            break;
        }
        else
        {
            a=a*10;
            i=i+1;
        }
    }




}
