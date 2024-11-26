#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter a number:");
    scanf("%d",&n);
    int m=n;
    int nsp=0;







    for(i=1;i<=n;i++)
    {
        for(int k=1;k<=nsp;k++)
            printf("  ");
        for(j=1;j<=m;j++)
        {
            printf("* ");
        }
        nsp++;
        printf("\n");
        m=m-2;

    }

}
