#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int sum=0,num=0;
    for(int i=1;i<=n;i++)
    {
        num=num*10+i;
        if(i<n)
            printf("%d+",num);
        else
            printf("%d=",num);
        sum=sum+num;
    }
    printf("%d",sum);
}