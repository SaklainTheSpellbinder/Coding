#include<stdio.h>
int factorial(int a)
{
    int s=1;
    for(int i=1;i<=a;i++)
    {
        s=s*i;
    }
    return s;
}
int main()
{
   int n;
   printf("Enter a number:");
   scanf("%d",&n);
   for(int i=0;i<=n;i++)
   {
    printf("%d!=%d\n",i,factorial(i));
   }
return 0;

}