#include<stdio.h>
int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++)
    {
        for(int j=1;j<=2*n-1;j++)
        {
            int m=i;
                if(i>n)
                  m=2*n-i;
            int k=j;
                if(j>n)
                k=2*n-j;
                if(m>k)
                printf("%d ",k);
                else
                printf("%d ",m); 
        }
        printf("\n");
    }
    return 0;
}