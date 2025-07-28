#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int countunique(vector<int>&nums,int si,int ei){
    if(si>ei){
        return 0;
    }
    if(si==ei){
        int mid=si;
        if((mid==nums.size()-1 || nums[mid]!=nums[mid+1])){
            return 1;
        }
        return 0;
    }
    int mid=si+(ei-si)/2;
    int left=countunique(nums,si,mid);
    int right=countunique(nums,mid+1,ei);
    return left+right;

}

int main() {
    FAST_IO;
    int count=0;
    vector<int>arr={1,3,3,5};
    count=countunique(arr,0,arr.size()-1);
    cout<<count<<endl;
    return 0;
}