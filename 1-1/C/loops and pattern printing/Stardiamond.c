#include<stdio.h>
int main()
{
    int n;
    printf("Enter odd Number:");
    scanf("%d",&n);
    int nsp=n/2;
    int nst=1;
    int ml=(n+1)/2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=nsp;j++)
            printf("  ");//space
        for(int k=1;k<=nst;k++)
            printf("* ");//stars
        if(i<ml)
        {
            nsp--;
            nst+=2;
        }
        else
        {
            nsp++;
            nst-=2;
        }
        printf("\n");
    }
    return 0;
}
