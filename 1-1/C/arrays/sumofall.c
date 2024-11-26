#include<stdio.h>
int main()
{
    int arr[5];
    printf("Enter the numbers:");
    for(int i=0;i<=4;i++)
    {
       scanf("%d",&arr[i]);
    }
    int sum=1;
    for(int i=0;i<=4;i++)
    {
    sum=sum*arr[i];
    }
    printf("The sum is %d",sum);
    return 0;
}