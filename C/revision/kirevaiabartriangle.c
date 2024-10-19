#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=(n-i);k++){
            printf(" ");
        }
        for(int j=i;j>=1;j--)
        {
            printf("%c",(char)(j+64));
        }
        printf("\n");
    }
}