#include<stdio.h>
int main(){
    int a,b,c,s,m;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)
    {
        m=a;
        s=b;
    }
    else
    {
        m=b;
        s=a;
}
    if(c>m)
    {
        s=m;
        m=c;
    }
    else if(c>s)
    {
        s=c;
    }
    printf("%d",s);
}