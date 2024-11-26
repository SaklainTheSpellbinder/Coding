#include<stdio.h>
int main()
{
    int i,j,p,n;
    printf("No of lines?\n");
    scanf("%d",&n);
    printf("Stars in each line?\n");
    scanf("%d",&p);
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=p;j++)
            {printf("%d\t",j);}
            printf("\n");
        }
    return 0;
}
