#include<stdio.h>
int power(int a,int b){
    if(b==0)
    return 1;
    if(b==1)
    return a;
    if(b%2==0)
    return power(a,b/2)*power(a,b/2);
    if(b%2!=0)
    return power(a,(b/2)+1)*power(a,b/2);
}
int main()
{
    int n,m;
    printf("Enter the base:");
    scanf("%d",&n);
    printf("Enter the power:");
    scanf("%d",&m);
    printf("The answer is %d",power(n,m));
    return 0;
}