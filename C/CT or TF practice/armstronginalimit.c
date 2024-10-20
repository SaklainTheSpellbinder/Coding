#include<stdio.h>
#include<limits.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int min=INT_MAX,max=INT_MIN;
    int temp=0;
    for(int i=a;i<=b;i++)
    {
        int j=i,sum=0;
        while(j!=0)
        {
            int r=j%10;
            sum=sum+r*r*r;
            j/=10;
        }
        if(sum==i)
        {   
            temp=1;
            if(sum>max)
                max=sum;
            if(sum<min)
                min=sum;
        }
    }
    if(temp)
        printf("%d %d",max,min);
    else
        printf("-1");
    return 0;
}