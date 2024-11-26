#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int min=24567894;
    int smin=24535567;
    if(a<min)
    {
        smin=min;
        min=a;
    }
    else if(a<smin)
    {
        smin=a;
    }
    if(b<min)
    {
        smin=min;
        min=b;
    }
    else if(b<smin)
    {
        smin=b;
    }
    if(c<min)
    {
        smin=min;
        min=c;
    }
    else if(c<smin)
    {
        smin=c;
    }
    printf("%d",smin);
    return 0;
}