#include<stdio.h>
int main(){
    int arr[5]={1,2,4,5,3};
    int minindex;
    for(int i=0;i<4;i++){
        minindex=i;
        for(int j=i+1;j<5;j++){
            if(arr[j]<arr[minindex])
                minindex=j;
        }
        int temp=arr[i];
        arr[i]=arr[minindex];
        arr[minindex]=temp;
    }
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}