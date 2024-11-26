#include<stdio.h>
#include<limits.h>
int indexOfMin(int arr[],int p,int n)
{
    int i=INT_MAX;
    int w;
    for(int j=p;j<n;j++)
    {
        if(i>arr[j])
        {
            i=arr[j];
            w=j;
        }
    }
    return w;
}
int main(){
    int arr[]={7,4,5,8,8,2,1};
    int n=7;
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(int i=0;i<n-1;i++)//n-1 passes
    {
        for(int j=i;j<n;j++)
        {
            int y=indexOfMin(arr,i,n);
            int temp=arr[y];
            arr[y]=arr[i];
            arr[i]=temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}