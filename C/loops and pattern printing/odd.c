#include<stdio.h>
int main()
{
    int i,n;
    printf("enter");
    scanf("%d",&n);
    int d=2^(n-1);
    for(i=1;i<=d;i=i*2)
    printf("%d\n",i);


}
