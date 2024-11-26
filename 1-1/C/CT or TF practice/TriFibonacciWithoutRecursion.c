#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a=0,b=1,c=1,sum=a+b+c;
    if(n==1)
        printf("%d ",a);
    if(n==2)
        printf("%d %d ",a,b);
    if(n>=3)
        printf("%d %d %d ",a,b,c);
    for(int i=4;i<=n;i++){
        sum=a+b+c;
        printf("%d ",sum);
        a=b;
        b=c;
        c=sum; 
    }
}