#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(nums[mid]<target && target<=nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int recursearch(vector<int>&nums,int si,int ei,int target){
    if(si>ei)
        return -1;
    int mid=si+(ei-si)/2;
    if(nums[mid]==target){
        return mid;
    }
    if(nums[si]<=nums[mid]){
        if(nums[si]<=target && target<=nums[mid]){
            return recursearch(nums,si,mid-1,target);
        }
        else{
            return recursearch(nums,mid+1,ei,target);
        }
    }
    else{
        if(nums[mid]<=target && target<=nums[ei]){
            return recursearch(nums,mid+1,ei,target);
        }
        else{
            return recursearch(nums,si,mid-1,target); 
        }
    }
}

int main(){
    vector<int>arr={5,6,7,8,9,89,1,2,3,4,5};
    cout<<search(arr,89)<<endl;
    cout<<recursearch(arr,0,arr.size()-1,89);
}