#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int cur=arr[i];
        int prev=i-1;
        while(arr[prev]<cur && prev>=0){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1]=cur;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
    
int main(){
    int arr[]={1,3,4,3,5,6,3,2,2,1,45,4545,45,2,2,12,3434,34,34,34,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr,n);
}