#include<stdio.h>
#include<limits.h>
#include<string.h>

int findMax(int arr[],int j,int n){
    int max=INT_MIN;
    int maxindex;
    for(int i=j;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            maxindex=i;
        }
    }
    return maxindex;
}

void swap(int arr[],int a,int b)
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

int main()
{
    int arr[5]={1,2,3,3,5};
    int n=5;
    for(int i=0;i<n;i++)
    {
        int index=findMax(arr,i,n);
        swap(arr,index,i);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}