#include<stdio.h>
int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int a=0;
    int b=1;
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a);
        int result=a+b;
        a=b;
        b=result;
    }
    return 0;
}