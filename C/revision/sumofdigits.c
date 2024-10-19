#include<stdio.h>
int main(){
    int n,r=0,a;
    printf("Enter the number: ");
    scanf("%d",&n);
    int s=n;
    while(n!=0)
    {
        a=n%10;
        r=r*10+a;
        n=n/10;
    }
    printf("The reverse number is %d \nThe sum of number and its reverse is %d ",r,r+s);
    return 0;
}