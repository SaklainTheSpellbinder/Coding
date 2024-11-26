#include<stdio.h>
void swap(int arr[],int a)
{
    int temp=arr[a];
    arr[a]=arr[a+1];
    arr[a+1]=temp;
}
int main(){
    int arr[6]={5,6,7,222,8,9};
    int n=6,k;
    printf("Enter the value of k:");
    scanf("%d",&k);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i;j>=0;j--)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr,j);
            }
        }
    }
    printf("The kth smallest value is : %d\n",arr[k-1]);
    return 0;
}