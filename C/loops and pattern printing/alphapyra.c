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
                printf("%c ",(char)(i+j-n+64));
            else if(j>n && j<(n+i))
                printf("%c ",(char)(n+i-j+64));
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}
