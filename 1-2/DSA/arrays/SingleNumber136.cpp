#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
    public:
        int singleNumberting(vector<int>& nums) {
            unordered_set<int>s;
            for(int i=0;i<nums.size();i++){
                if(s.count(nums[i])){
                    s.erase(nums[i]);
                }
                else{
                    s.insert(nums[i]);
                }
            }
            int ans;
            for(auto it:s)
                ans=it;
            return ans;
        }

        int singleNumber(vector<int>& nums){
            int res=nums[0];
            for(int i=1;i<nums.size();i++){
                res^=nums[i];
            }
            return res;
        }
};