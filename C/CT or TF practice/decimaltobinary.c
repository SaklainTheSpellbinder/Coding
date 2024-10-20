#include<stdio.h>
#include<math.h>
int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    int sum=0,nm=0;
    int yo=1;
    while(n!=0)
    {
        int r=n%2;
        if(r==1)
            nm++;
        n=n/2;
        sum=sum+r*yo;
        yo*=10;

    }
    printf("%d\n",sum);
    int newdec=0;
    for(int i=0;i<nm;i++)
    {
        int d=pow(2,i);
        newdec+=d;
    }
    printf("%d",newdec);
    return  0;
}