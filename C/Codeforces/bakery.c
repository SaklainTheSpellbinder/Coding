#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,a,b;
        int profit=0;
        scanf("%d%d%d",&n,&a,&b);
        if(a>=b)
        {
            profit=profit+a*n;
        }
        else
        {
            int p=1;
            while(b>a)
            {
                b=b-p+1;
                p++;
                profit=profit+b;
            }
            profit=profit+(n-p+1)*a;
        }
        printf("%d\n",profit);
    }
}