#include<stdio.h>
#include<math.h>
#include<limits.h>

int digits(int n){
    int count=0;
    while(n!=0)
    {
        n/=10;
        count++;
    }
    return count;
}

int armstrong(int n)
{
    int dig=digits(n);
    int sum=0;
    int real=n;
    while(n!=0)
    {
        int r=n%10;
        n/=10;
        sum=sum+pow(r,dig);
    }
    if(sum==real)
        return 1;
    else
        return 0;
}

int main()
{
    int n,m;
    printf("Enter two numbers:");
    scanf("%d%d",&m,&n);    
    int min=INT_MAX;
    int max=INT_MIN;
    int temp=0;
    for(int i=m;i<=n;i++)
    {
        if(armstrong(i))
        {
            if(i>max)
                max=i;
            if(i<min)
                min=i;
            temp=1;
        }
    }
    if(temp)
        printf("%d %d",max,min);
    else
        printf("-1");
    return 0;
}