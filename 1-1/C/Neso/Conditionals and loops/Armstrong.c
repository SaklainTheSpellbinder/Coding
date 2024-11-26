#include<stdio.h>
#include<math.h>


int digits(int n){
    int i=0;
    while(n!=0)
    {
        n=n/10;
        i++;
    }
    return i;
}


int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    int sum=0,r,dig=digits(n),real=n;
    while(n!=0)
    {
        r=n%10;
        n=n/10;
        sum=sum+pow(r,dig);
    }
    if(sum==real)
    {
        printf("Armstrong");
    }
    else
        printf("Not Armstrong");
    return 0;
}