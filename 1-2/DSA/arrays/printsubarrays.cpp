#include <iostream>
using namespace std;

void subarray(int arr[],int n){
    for(int start=0;start<n;start++){
        for(int end=start;end<n;end++){
            for(int i=start;i<=end;i++){
                cout<<arr[i];
            }
            cout<<" ,";
        }
        cout<<"\n";
    }
}

int main() {
    int arr[]={1,3,4,5,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    subarray(arr,n);
    return 0;
}