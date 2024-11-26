#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    float b=sqrt(a);
    printf("%f\n",b);
    int q=pow(a,b);
    printf("%d",q);
    return 0;
}