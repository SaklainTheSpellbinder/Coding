#include<stdio.h>
#include<limits.h>
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int max;
    int smax;
    int tmax;
    int qmax;
    long long int t=a+b+c+d;
    if(a>b && a>c && a>d)
    {
        max=a;
        a=INT_MIN;
    }
    else if(b>c && b>d)
    {
        max=b;
        b=INT_MIN;
    }
    else if(c>d)
    {
        max=c;
        c=INT_MIN;
    }
    else{
        max=d; 
        d=INT_MIN;
    }

    if(a>b && a>c && a>d)
    {
        smax=a;
        a=INT_MIN;
    }
    else if(b>c && b>d)
    {
        smax=b;
        b=INT_MIN;
    }
    else if(c>d)
    {
        smax=c;
        c=INT_MIN;
    }
    else{
        smax=d; 
        d=INT_MIN;
    }

    if(a>b && a>c && a>d)
    {
        tmax=a;
        a=INT_MIN;
    }
    else if(b>c && b>d)
    {
        tmax=b;
        b=INT_MIN;
    }
    else if(c>d)
    {
        tmax=c;
        c=INT_MIN;
    }
    else{
        tmax=d; 
        d=INT_MIN;
    }

    qmax=t-max-smax-tmax;
    printf("%d %d %d %d",qmax,tmax,smax,max);
    return 0;
}