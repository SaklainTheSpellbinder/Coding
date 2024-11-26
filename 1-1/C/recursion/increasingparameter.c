#include<stdio.h>
void increasing(int x,int n)
{
    printf("%d\n",x);
    if(x==n)
    return;
    increasing(x+1,n);
}
int main()
{
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    increasing(1,a);
    return 0;
}