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
                printf("%d ",j);
        }
        else
        {
            for(int k=1;k<=nst;k++)
                printf("%d ",k);
            for(int m=1;m<=nsp;m++)
                printf("  ");
            for(int l=1;l<=nst;l++)
                printf("%d ",(n/2)-1+i+l);
            nst--;
            nsp+=2;
        }
        printf("\n");
    }
    return 0;
}
