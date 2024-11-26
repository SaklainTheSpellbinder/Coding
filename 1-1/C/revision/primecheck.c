#include<stdio.h>
int main()
{
    int n,a=0;
    printf("Enter a Number: ");
    scanf("%d",&n);
    if(n<=0)
    printf("Only Positive integers are allowed");
    else if(n==1)
    printf("Neither prime nor composite");
    else if(n==2)
    printf("Prime");
    else{
        for(int i=2;i<n;i++)
        {
            if(n%i==0)
            {
                a=1;
                break;
            }
        }
        if(a==1)
        printf("Not Prime");
        else
        printf("Prime");
    }
    return 0;
}