#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int peakidx(vector<int>&arr,int si,int ei){//gadha saklain
    if(si>ei){
        return -1;
    }
    if(si==ei){
        if((si==0 && arr[si]>=arr[si+1]) || (si==arr.size()-1 && arr[si-1]<=arr[si]) || (arr[si-1]<=arr[si] && arr[si]>=arr[si+1])){
            return si;
        }
        else
            return -1;
    }

    int mid=si+(ei-si)/2;
    int left=peakidx(arr,si,mid);
    int right=peakidx(arr,mid+1,ei);
    if(left!=-1){
        return left;
    }
    else if(right!=-1){
        return right;
    }
    else{
        return -1;
    }
}

int peakidxbinary(vector<int>&arr,int si,int ei){
    while(si<=ei){
        int mid=si+(ei-si)/2;
        bool left=(mid==0 || arr[mid]>=arr[mid-1]);
        bool right=(mid==arr.size()-1 || arr[mid]>=arr[mid+1]);
        if(left && right)   return mid;
        else if(mid>0 && arr[mid-1]>arr[mid]){
            ei=mid-1;
        }
        else{
            si=mid+1;
        }
    }
    return -1;
}

int main() {
    FAST_IO;
    int t;
    t=1;
    while(t--){
        vector<int>arr={8,9,10,2,5,6};
        cout<<arr[peakidxbinary(arr,0,arr.size()-1)]<<endl;
    }
    return 0;
}