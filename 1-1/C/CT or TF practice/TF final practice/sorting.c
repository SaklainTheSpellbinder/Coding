#include<stdio.h>
#define N 5
int main(){
    int arr[5]={5,4,3,2,1};
    for(int i=0;i<N;i++){
        int minidx=i;
        for(int j=i+1;j<N;j++){
            if(arr[minidx]>arr[j]){
                minidx=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minidx];
        arr[minidx]=temp;
    }
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}