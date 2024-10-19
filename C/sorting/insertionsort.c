#include<stdio.h>
int main(){
    int arr[5]={1,5,3,0,2};
    int n=5;
    for(int i=1;i<n;i++)
    {
        int j=i;
        while(arr[j]<arr[j-1] && j>0)
        {
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
    for(int i=0;i<n;i++)
    {    
        printf("%d ",arr[i]);
    }
}