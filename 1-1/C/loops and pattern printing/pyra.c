#include<stdio.h>
int main()
{
    int i,n,j;
    printf("Enter a Number:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(i%2==0)
                printf("%c",(char)(j+64));
            else
                printf("%d",j);
        }
        printf("\n");
    }



}
