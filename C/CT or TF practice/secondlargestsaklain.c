#include<stdio.h>
#include<limits.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int max=a;
    int smax=INT_MIN;
    if(b>=max)
    {
        smax=max;
        max=b;
    }
    else if(b>=smax)
    {
        smax=b;
    }
    
    if(c>=max)
    {
        smax=max;
        max=c;
    }
    else if(c>=smax){
        smax=c;
    }
    printf("%d",smax);
}