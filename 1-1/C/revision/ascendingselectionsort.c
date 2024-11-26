#include<stdio.h>
#include<limits.h>
#include<string.h>

int findMin(int arr[],int j,int n){
    int min=INT_MAX;
    int minindex;
    for(int i=j;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
            minindex=i;
        }
    }
    return minindex;
}

void swap(int arr[],int a,int b)
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

int main()
{
    int arr[5]={5,4,3,2,1};
    int n=5;
    for(int i=0;i<n;i++)
    {
        int index=findMin(arr,i,n);
        swap(arr,index,i);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}