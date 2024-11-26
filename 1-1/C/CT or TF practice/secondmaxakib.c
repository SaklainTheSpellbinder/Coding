#include<stdio.h>
#include<limits.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int max,smax;
    if(a>b && a>c)
    {
        max=a;
        a=INT_MIN;
    }
    else if(b>c)
    {
        max=b;
        b=INT_MIN;
    }
    else{
        max=c;
        c=INT_MIN;
    }

    if(a>b && a>c)
    {
        smax=a;
        a=INT_MIN;
    }
    else if(b>c)
    {
        smax=b;
        b=INT_MIN;
    }
    else{
        smax=c;
        c=INT_MIN;
    }
    
    printf("The second largest: %d",smax);
}