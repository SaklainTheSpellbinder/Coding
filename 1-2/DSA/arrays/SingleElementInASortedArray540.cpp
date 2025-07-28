#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid==0  || mid==nums.size()-1){
            return nums[mid];
        }
        else if((nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])){
            return nums[mid];
        }
        else if(nums[mid]==nums[mid-1]){
            if((mid-low)%2==0){
                high=mid-2;
            }
            else{
                low=mid+1;
            }
        }
        else if (nums[mid]==nums[mid+1]){
            if((high-mid)%2==0){
                low=mid+2;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int main(){

}