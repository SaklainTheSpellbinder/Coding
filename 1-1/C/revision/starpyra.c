#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int m=(n/2)+1;
    for(int i=1;i<=m;i++)
    {
        for(int k=1;k<=(m-i);k++)
        {
            printf(" ");
        }
        for(int j=1;j<=(2*i-1);j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int i=1;i<=(n-m);i++){
        for(int k=1;k<=i;k++)
        {
            printf(" ");
        }
        for(int j=1;j<=2*((n-m)-i+1)-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}