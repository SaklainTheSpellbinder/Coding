#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

void heapify(int i,vector<int>&arr,int n){
    if(i>=n){
        return;
    }

    int l=2*i+1;
    int r=2*i+2;

    int maxI=i;

    if(l<n && arr[maxI]<arr[l]){// ">" use krle descending order e hbe
        maxI=l;
    }
    if(r<n && arr[maxI]<arr[r]){
        maxI=r;
    }
    if(maxI!=i){
        swap(arr[maxI],arr[i]);
        heapify(maxI,arr,n);
    }
}

void heapsort(vector<int>&arr){
    int n=arr.size();
    for(int i=(n/2)-1;i>=0;i--){   //O(n*logn)
        heapify(i,arr,n);
    }

    for(int i=n-1;i>=0;i--){      //O(n*logn)
        swap(arr[0],arr[i]);
        heapify(0,arr,i);
    }
}

int main(){
    vector<int>arr={1,4,2,5,3};
    heapsort(arr);
    for(auto &it: arr){
        cout<<it<<" ";
    }
    cout<<endl;
}