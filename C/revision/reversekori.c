#include<stdio.h>
int main(){
    int r,new=0,n;
    printf("Enter a number:");
    scanf("%d",&n);
    while(n)
    {
        r=n%10;
        n/=10;
        new=new*10+r;
    }
    printf("The reverse is : %d",new);
    return 0;
}