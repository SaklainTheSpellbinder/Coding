#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter the number:");
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {
        for(j=i;j>=1;j--)
        {
            int p=2*j-1;
            printf("%d ",p);
        }
        printf("\n");
    }
    return 0;
}
