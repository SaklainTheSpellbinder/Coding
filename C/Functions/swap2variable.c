#include<stdio.h>
int main()
{
    int m,n;
    printf("Enter two numbers:");
    scanf("%d%d",&m,&n);
    m=m+n;
    n=m-n;
    m=m-n;
    printf("%d and %d ",m,n);
    return 0;
}