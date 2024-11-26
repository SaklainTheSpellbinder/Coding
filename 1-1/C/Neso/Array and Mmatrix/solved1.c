#include<stdio.h>

void swap(int arr[],int i,int n)
{
    int temp=arr[i];
    arr[i]=arr[n-1-i];
    arr[n-1-i]=temp;
    return;
}

int main(){
    int arr[9]={34,56,54,32,67,89,90,32,21};
    int n=9;
     for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(int i=0;i<=(n/2);i++)
    {
        swap(arr,i,n);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;

}