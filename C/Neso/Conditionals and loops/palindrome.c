#include<stdio.h>


int reverse(int n)
{
    int s=0,r;
    while(n!=0)
    {
        r=n%10;
        n=n/10;
        s=s*10+r;
    }
    return s;
}


int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    int rn=reverse(n);
    if(rn==n)
    {
        printf("Palindrome");
    }
    else
        printf("Not a Palindrome");
    return 0;
}