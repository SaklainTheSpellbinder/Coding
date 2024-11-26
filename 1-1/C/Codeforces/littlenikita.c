#include<stdio.h>
int main(){
    int t,n,m;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&m);
        int temp=0;
        if((n%2==0 && m%2==0)||(n%2!=0 && m%2!=0))
        temp=1;
        if(temp==1){
        if(n>=m)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        }
        else
        printf("No\n");
    }
    return 0;
}