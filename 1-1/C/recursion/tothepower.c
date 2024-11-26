#include<stdio.h>
int power(int a,int b)
{
    if(b==0)
    return 1;
    return a*power(a,b-1);
}
int main()
{
    int x,y;
    printf("Enter the base:");
    scanf("%d",&x);
    printf("Enter the power:");
    scanf("%d",&y);
    printf("The answer is %d",power(x,y));
    return 0;
}