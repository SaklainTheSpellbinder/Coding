#include<stdio.h>
void selectionsort(int arr[],int a,int b){
    for(int i=a;i<=b;i++){
        int minidx=i;
        for(int j=i+1;j<=b;j++){
            if(arr[j]<arr[minidx]){
                minidx=j;
            }
        }
        int temp=arr[minidx];
        arr[minidx]=arr[i];
        arr[i]=temp;
    }
    return;
}
int main(){
    int arr[]={4,2,4,5,6,3,2,2,2,2,2,2,23545555,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,0,8);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}