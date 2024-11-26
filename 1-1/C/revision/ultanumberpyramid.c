#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=(n-i);k++)\
        {
            printf(" ");
        }
        for(int j=1;j<=(2*i-1);j++)
        {
            if(j<=i){
            printf("%c",(char)(j+64));
            }
            else
                printf("%c",(char)(2*i-j+64));
        }
        printf("\n");
    }
}