#include<stdio.h>
int main()
{
    int n;

    printf("Enter row: ");
    scanf("%d",&n);

    int nsp=1;
    int nsn=n-1;

    for(int i=1;i<=n;i++)
    {
        int count=1;
        if(i==1)
        {
            for(int j=1;j<=(2*n-1);j++)
            {
                printf("%c ",64+count);
                count++;
            }
        }
        else
        {
            for(int j=1;j<=nsn;j++)
            {
                printf("%c ",64+count);
                count++;
            }
            for(int k=1;k<=nsp;k++)
            {
                printf("  ");
                count++;
            }
            for(int m=nsn;m>=1;m--)
            {
                printf("%c ",64+count);
                count++;
            }
            nsp+=2;
            nsn--;
        }
        printf("\n");
    }

    return 0;
}