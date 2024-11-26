#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int count=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=count;j++)
        {
            printf("*");
        }
        count+=2;
        printf("\n");
    }
}