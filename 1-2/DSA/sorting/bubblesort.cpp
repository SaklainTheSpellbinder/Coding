#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool isSwap=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
        }
        if(!isSwap){
            return;
        }
    }
}

int main(){
    int arr[]={1,3,3,1,43,2,2,2,234,3434,34,34,34,34,34,2,2,2,1,5,6,7,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}