#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter a Number:");
    scanf("%d",&n);
    int p=ceil(sqrt(n));
    int temp=0;
    for(int i=2;i<=p;i++)
    {
        if(n%i==0)
        {
            temp=1;
            break;
        }
    }
    if((temp==0 ||n==2||n==3) && n>1)
        printf("Prime");
    else
        printf("Not Prime");
    return 0;
}