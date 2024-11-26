#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        int sum=0;
        int j;
        for(int x=2;x<=n;x++)
        {
            int m=0;
            int k=1;
            while(k*x<=n)
            {
                m=m+k*x;
                k++;
            }
            if(m>sum)
            {
                sum=m;
                j=x;
            }
        }
        printf("%d\n",j);
    }
}