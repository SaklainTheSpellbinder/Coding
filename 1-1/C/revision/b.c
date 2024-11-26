#include<stdio.h>
int main(){
    int t;
    long long x,y,k;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
        scanf("%lld%lld%lld",&x,&y,&k);
        for(long long i=1;i<=k;i++)
        {
            x++;
            while(x%y==0)
                x=x/y;
        }
        printf("%lld",x);
    }
    return 0;
}