#include<stdio.h>
int main()
{
    int i=1,n,s=0;
    printf("Enter");
    scanf("%d",&n);
    while(i<=n)
    {
        if(i%2==0)
            s=s-i;
        else
            s=s+i;
        i=i+1;
    }
    printf("Sum:%d",s);
}
