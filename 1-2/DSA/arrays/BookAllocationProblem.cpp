#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//this is the same code of painter's partition problem also

bool isValid(vector<int>&arr,int n,int m,int maxallowed){//O(n)
    int stu=1,pages=0;

    for(int i=0;i<n;i++){
        if(arr[i]>maxallowed)
            return false;
        if(pages+arr[i]<=maxallowed){
            pages+=arr[i];
        }
        else{
            stu++;
            pages=arr[i];
        }
    }

    return (stu>m)? false:true;
}

int allocatedBooks(vector<int> &arr,int n,int m){//O(logn * n)
    if(m>n)
        return -1;
    int sum = 0, maxBook = 0;
    for (int i = 0; i < n; i++) { // O(n)
        sum += arr[i];
        maxBook = max(maxBook, arr[i]);
    }
    
    int st = maxBook; // Start with the maximum book size
    int end = sum; // End with the total sum of pages
    int ans = -1;
    
    
    while(st<=end){//O(logn)
        int mid=st+(end-st)/2;
        if(isValid(arr,n,m,mid)){//left
            ans=mid;
            end=mid-1;
        }
        else{//right
            st=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int>arr={40,30,10,20};
    int n=4,m=2;

    cout<<allocatedBooks(arr,n,m)<<endl;
}