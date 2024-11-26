#include<stdio.h>
void reverse(int arr[],int a,int b)
{
    for(int i=a,j=b-1;i<j;i++,j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    return;
}

int main(){
    int arr[7]={1,2,3,4,5,6,7};
    int n=7;
    int k;
    printf("Enter k: ");
    scanf("%d",&k);
    if(k>=n)
    {
        k=k%n;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    reverse(arr,0,n);
    reverse(arr,0,k);
    reverse(arr,k,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}