#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=(n/2)+1;i++)
    {
        if(i==1)
        {
            for(int j=1;j<=n;j++)
                printf("*");
        }
        else
        {
            for(int j=1;j<=((n/2)+2-i);j++)
                printf("*");
            for(int k=1;k<=(2*i-3);k++)
                printf(" ");
            for(int l=((n/2)+2-i);l>=1;l--)
                printf("*");
        }
        printf("\n");
    }
    return 0;
}