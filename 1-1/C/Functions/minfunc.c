#include<stdio.h>
int minimum(int a, int b)
{
    int c=a;
    if(a>b)
    c=b;
    return c;
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int min=minimum(m,n);
    printf("%d",min);
    return 0;
}