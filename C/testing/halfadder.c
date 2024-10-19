#include<stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int sum=0,carry=0;;
    while(b)
    {
        sum=a^b;
        carry=(a&b)<<1;
        a=sum;
        b=carry;
    }
    printf("The sum is: %d",sum);
}