#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int f1=0;
    int f2=1;
    int f3=1;
    if(n==1)
        printf("%d ",f1);
    if(n==2)
        printf("%d %d ",f1,f2);
    if(n>=3)
    {
        printf("%d %d %d ",f1,f2,f3);
        int i=4;
        while(i<=n)
        {
            int result =f1+f2+f3;
            f1=f2;
            f2=f3;
            f3=result;
            printf("%d ",result);
            i++;
        }
    }
    return 0;
}