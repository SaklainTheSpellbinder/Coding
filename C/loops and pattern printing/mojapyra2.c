#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter layer Number:");
    scanf("%d",&n);
    int nsp=n-1;
    for(i=1;i<=n;i++)
    {
        for(int q=1;q<=nsp;q++)
            printf("  ");
        nsp--;
        for(j=1;j<=i;j++)
            printf("%d ",j);
        int m=i-1;
        for(int k=1;k<=(i-1);k++)
        {
            printf("%d ",m);
            m--;
        }
        printf("\n");
    }
    return 0;
}
