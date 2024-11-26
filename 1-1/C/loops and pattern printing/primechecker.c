#include<stdio.h>
int main()
{
    int a,n;
    a=1;
    printf("Enter number:");
    scanf("%d",&n);
    if(n==2)
        {printf("Prime");
        }
    else if(n==1)
        {printf("Not Prime");
        }
    else
    {
        for(int i=2;i<n;i++)
        {
            if(n%i==0)
            {
                a=0;
                break;
            }
        }
        if(a==0)
        printf("Not Prime");
    else
        printf("Prime");

    }

}
