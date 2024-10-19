#include<stdio.h>
int main(){
    int n,m;
    printf("Enter row:");
    scanf("%d",&n);
    printf("Enter coloumn:");
    scanf("%d",&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%c ",(char)(j+64));
        }
        printf("\n");
    }
    return 0;
}