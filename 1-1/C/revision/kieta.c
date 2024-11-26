#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=((n/2)+1);i++)
    {
        for(int j=1;j<=n;j++){
        if(i==1)
        {
            printf("*");
        }
        else
        {
            if((i+j)>=(n-1) && (i+j)<=(n+(2*(i-1))-3))
            {
                printf(" ");
                continue;
            }
            printf("*");
        }
        }
        printf("\n");
    }
}