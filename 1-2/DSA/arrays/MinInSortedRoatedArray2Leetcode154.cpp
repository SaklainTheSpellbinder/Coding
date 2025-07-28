#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findMin(vector<int>& nums) {
    sort(nums.begin(),nums.end());

    return nums[0];
}

int main(){
    vector<int>nums={10,1,10,10,10};
    cout<<findMin(nums);
}