#include<stdio.h>
void serial(int n)
{
    printf("%d\n",n);
    if(n>1)
    serial(n-1);
    return;
}
int main()
{
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    serial(a);
    return 0;
}
