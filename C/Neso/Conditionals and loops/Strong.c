#include<stdio.h>

int factorial(int n){
    if(n==1)
        return 1;
    else
        return n*factorial(n-1);
}


int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    int real=n,sum=0,r;
    while(n!=0)
    {
        r=n%10;
        n/=10;
        sum=sum+factorial(r);
    }
    if(sum==real)
    {
        printf("A Strong Number");
    }
    else
        printf("Not a strong number");
    return 0;
}