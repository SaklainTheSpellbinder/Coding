#include<stdio.h>
int main()
{
    int a,i,n;
    a=3;
    printf("To which termn?");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("%d\n",a);
        a=a*4;
    }
}
