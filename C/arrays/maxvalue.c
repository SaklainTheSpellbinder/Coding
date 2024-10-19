#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size:");
    scanf("%d",&n);
    int arr[n];
    printf("Entre the numbers:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    for(int j=0;j<n;j++)
    {
       if(arr[j]>max)
       max=arr[j];
    }
    printf("The max is %d",max);
    return 0;
}