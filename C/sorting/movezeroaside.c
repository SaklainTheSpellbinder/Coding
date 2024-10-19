#include<stdio.h>
int main(){
    int arr[9]={5,0,2,0,0,4,1,3,0};
    int n=9;
    for(int i=1;i<n;i++)
    {
        int j=i;
        while(j>0 && arr[j-1]==0){
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
    return 0;
}