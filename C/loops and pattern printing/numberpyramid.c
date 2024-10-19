#include<stdio.h>
int main()
{
    int i,j,m,n;
    printf("Enter a Number:");
    scanf("%d",&n);
    m=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d ",m);
            m=m+1;
        }
        printf("\n");
    }
    return 0;
}
