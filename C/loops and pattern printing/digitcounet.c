#include<stdio.h>
int main()
{
    int p,n,count=0;
    printf("Enter a number:");
    scanf("%d",&n);
    while(n!=0)
    {
        p=n%10;
        n=n/10;
        count=count+p;
    }
    printf("\nThe sum :%d",count);
    return 0;
}
