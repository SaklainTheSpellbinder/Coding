#include<stdio.h>
int numbermaker(int n)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=sum*10+i;
    }
    return sum;
}

int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=sum+numbermaker(i);
    }
    printf("%d",sum);
    return 0;
}