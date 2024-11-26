#include<stdio.h>
int main()
{
    int p,n,i;
    printf("Enter row:");
    scanf("%d",&n);
    printf("Enter Column:");
    scanf("%d",&p);
    for(i=1;i<=n;i++)
    {
        for(int j=1;j<=p;j++)
            { int u=j+64;
                printf("%c ",(char)u);
                }
        printf("\n");
    }
    return 0;
}
