#include<stdio.h>
void swap(int arr[],int a)
{
    int temp=arr[a];
    arr[a]=arr[a+1];
    arr[a+1]=temp;
}
int main(){
    int arr[9]={5,0,2,0,0,4,1,3,0};
    int n=9;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i;j>=0;j--)
        {
            if(arr[j]==0)
            {
                swap(arr,j);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}