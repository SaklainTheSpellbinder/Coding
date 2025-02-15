#include<stdio.h>
void merge(int arr[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int leftarray[n1];
    int rightarray[n2];
    for(int i=0;i<n1;i++){
        leftarray[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++){
        rightarray[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(leftarray[i]<rightarray[j]){
            arr[k++]=leftarray[i++];
        }
        else{
            arr[k++]=rightarray[j++];
        }
    }
    while(i<n1){
        arr[k++]=leftarray[i++];
    }
    while(j<n2){
        arr[k++]=rightarray[j++];
    }
    return;
}

void mergesort(int arr[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    return;
}

int main(){
    int arr[]={1,2,4,5,6,9,3,2};
    int n=sizeof(arr)/sizeof(int);
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}