#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        int midx=i;
        for(int j=i+1;j<n;j++){
            if(arr[midx]>arr[j])
                midx=j;
        }
        int temp=arr[midx];
        arr[midx]=arr[i];
        arr[i]=temp;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}