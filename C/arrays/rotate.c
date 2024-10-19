#include<stdio.h>
void reverse(int arr[],int i,int j){//reversing part of array
  while(i<=j)
  {
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    i++;
    j--;
  }
  return;
}
int main(){
    int k;
    printf("Enter the value of k:");
    scanf("%d",&k);
    int arr[7]={1,2,3,4,5,6,7};
    k=k%7;
    reverse(arr,0,6);
    reverse(arr,0,k-1);
    reverse(arr,k,6);
    for(int j=0;j<7;j++)
    {
        printf("%d ",arr[j]);
    }
    return 0;
}