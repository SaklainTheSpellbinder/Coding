#include<stdio.h>
void decinc(int n)
{
    if(n==0)
    return;
    printf("%d\n",n);
    decinc(n-1);
    printf("%d\n",n);
    return;
}
int main()
{
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    decinc(a);
    return 0;
}