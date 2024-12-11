#include<stdio.h>
int main(){
    int arr[10]={1,3,4,2,7,6,5,8,9,11};
    int n=10;
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        int temp=arr[minindex];
        arr[minindex]=arr[i];
        arr[i]=temp;
    }
    int bu=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=i+1){
            printf("Missing %d",i+1);
            bu=1;
            break;
        }
    }
    if(bu==0){
        printf("No missing");
    }
}