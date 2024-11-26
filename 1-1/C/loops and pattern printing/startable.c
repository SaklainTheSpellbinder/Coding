#include<stdio.h>
int main()
{
    int n;
    printf("Enter a odd number:");
    scanf("%d",&n);
    int nsp=1;
    int nst=n/2;
    int ml=(n/2)+1;
    for(int i=1;i<=ml;i++)
    {
        if(i==1)
        {
            for(int j=1;j<=n;j++)
                printf("* ");
        }
        else
        {
            for(int k=1;k<=nst;k++)
                printf("* ");
            for(int m=1;m<=nsp;m++)
                printf("  ");
            for(int l=1;l<=nst;l++)
                printf("* ");
            nst--;
            nsp+=2;
        }
        printf("\n");
    }
    return 0;
}
