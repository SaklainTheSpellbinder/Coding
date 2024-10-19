#include<stdio.h>
void swap(int arr[],int i)
{
    int temp=arr[i];
    arr[i]=arr[i+1];
    arr[i+1]=temp;
    return;
}
int main(){
    int arr[9]={5,0,2,0,0,4,1,3,0};
    int n=9;
    int j=n;
    while(j--)
    {
    for(int i=0;i<(n-1);i++)
    {
        if(arr[i]==0)
            swap(arr,i);
    }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}