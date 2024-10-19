#include<stdio.h>
int main(){
    int n;
    printf("Enter row number: ");
    scanf("%d",&n);
    for(int i=n;i>=1;i--)
    {
        for(int j=i;j>=1;j--)
        {
            printf("%d ",2*j-1);
        }
        printf("\n");
    }
    return 0;
}