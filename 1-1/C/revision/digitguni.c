#include<stdio.h>
int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    int count=0,sum=0;
    int r;
    while(n)
    {
        count++;
        if(count%2==0){
        r=n%10;
        sum+=r;
        }
        n/=10;
    }
    printf("SUm: %d",sum);
    return 0;
}