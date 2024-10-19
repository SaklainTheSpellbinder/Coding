#include<stdio.h>
#include<limits.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int max=a;
    int smax=INT_MIN;
    if(b>max)
    {
        max=b;
    }
    
    if(c>max)
    {
        max=c;
    }

    if(a>smax && a!=max)
    {
        smax=a;
    }

    if(b>smax && b!=max)
    {
        smax=b;
    }
    if(c>smax && c!=max)
    {
        smax=c;
    }
    printf("The second max is %d",smax);
    return 0;
}