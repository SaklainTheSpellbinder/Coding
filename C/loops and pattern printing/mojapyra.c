#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter layer number:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<(2*n);j++)
        {
            if(j>(n-i) && j<=n)
                printf("%d ",i+j-n);
            else if(j>n && j<(n+i))
                printf("%d ",n+i-j);
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}
