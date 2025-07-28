#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findMin(vector<int>& nums) {
    int minm=INT32_MAX;
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[low]<=nums[mid]){
            minm=min(nums[low],minm);
            low=mid+1;
        }
        else{
            minm=min(nums[mid],minm);
            high=mid-1;
        }
    }
    return minm;
}

int main(){
    vector<int>nums={7,1,2,3,4,5};
    cout<<findMin(nums);
}