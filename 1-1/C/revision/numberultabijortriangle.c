#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=n;i>=1;i--)
    {
        int count=2*i-1;
        for(int j=i;j>=1;j--){
            printf("%d",count);
            count-=2;
        }
        printf("\n");
    }
}