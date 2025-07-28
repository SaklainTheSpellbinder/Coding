#include<iostream>
#include<algorithm>
using namespace std;

int partition(int arr[],int si,int ei){
    int i=si-1;
    int pivot=arr[ei];
    for(int j=si;j<ei;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);
    return i; 
}

void quicksort(int arr[],int si,int ei){
    if(si>=ei){
        return;
    }

    int pivotidx=partition(arr,si,ei);

    quicksort(arr,si,pivotidx-1);
    quicksort(arr,pivotidx+1,ei);
}

int main(){
    int arr[]={1,3,4,5,3,32,2,1,1,22,3123,213,233,23,23,23,23,23,23,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}