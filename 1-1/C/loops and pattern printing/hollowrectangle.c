#include<stdio.h>
int main()
{
    int i,j,m,n;
    printf("Enter row:");
    scanf("%d",&n);
    printf("Enter column:");
    scanf("%d",&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(i==1 || i==n)
                printf("* ");
            else if(j==1 || j==m)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}
