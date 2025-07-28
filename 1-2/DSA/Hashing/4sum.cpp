#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n=nums.size();
            vector<vector<int>>ans;
            sort(nums.begin(),nums.end());

            for(int i=0;i<n;i++){
                if(i>0 && nums[i]==nums[i-1])
                    continue;
                for(int j=i+1;j<n;){
                    int p=j+1;
                    int q=n-1;
                    while(p<q){
                        long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[p]+(long long)nums[q];
                        if(sum<target)
                            p++;
                        else if(sum>target)
                            q--;
                        else{
                            ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                            p++;
                            q--;
                            while(p<q && nums[p]==nums[p-1])
                                p++;
                        }
                    }

                    j++;
                    while(j<n && nums[j]==nums[j-1])
                        j++;
                }
            }
            return ans;
        }

            //  vector<vector<int>> fourSuM(vector<int>& nums, int target) {
            //    vector<vector<int>> ans;
            //    vector<int> path;
            //    ranges::sort(nums);
            //    nSum(nums, 4, target, 0, nums.size() - 1, path, ans);
            //    return ans;
            //  }
           
            // private:
             
            //  void nSum(const vector<int>& nums, long n, long target, int l, int r,
            //            vector<int>& path, vector<vector<int>>& ans) {
            //    if (r - l + 1 < n || target < nums[l] * n || target > nums[r] * n)
            //      return;
            //    if (n == 2) {
           
            //      while (l < r) {
            //        const int sum = nums[l] + nums[r];
            //        if (sum == target) {
            //          path.push_back(nums[l]);
            //          path.push_back(nums[r]);
            //          ans.push_back(path);
            //          path.pop_back();
            //          path.pop_back();
            //          ++l;
            //          --r;
            //          while (l < r && nums[l] == nums[l - 1])
            //            ++l;
            //          while (l < r && nums[r] == nums[r + 1])
            //            --r;
            //        } else if (sum < target) {
            //          ++l;
            //        } else {
            //          --r;
            //        }
            //      }
            //      return;
            //    }
           
            //    for (int i = l; i <= r; ++i) {
            //      if (i > l && nums[i] == nums[i - 1])
            //        continue;
            //      path.push_back(nums[i]);
            //      nSum(nums, n - 1, target - nums[i], i + 1, r, path, ans);
            //      path.pop_back();
            //    }
            //  }    
};

int main(){

}