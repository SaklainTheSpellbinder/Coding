#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minidx=i;
        for(int j=i;j<n;j++){
            if(arr[minidx]>arr[j])
                minidx=j;
        }
        swap(arr[minidx],arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={2,4,5,3,2,1,1,4,6,7,8,6,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,n);
}