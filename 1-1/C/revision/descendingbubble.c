#include<stdio.h>
#include<stdbool.h>
int main()
{
    int arr[5]={1,2,3,4,5};
    int n=5;
    for(int i=1;i<n;i++)
    {
        bool flag=true;
        for(int j=0;j<(n-i);j++)
        {
            if(arr[j+1]>arr[j])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=false;
            }
            if(flag==true)
                break;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}