#include<stdio.h>
int main(){
    int n,i,a;
    printf("To which Term:");
    scanf("%d",&n);
    a=1;
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",a);
        a*=2;
    }
    
    return 0;
}