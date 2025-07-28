#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>

using namespace std;


class Solution {
    public:
        vector<vector<int>> threeSumBruteForce(vector<int>& nums) {//bruteforce approach
            vector<vector<int>>ans;   //O(n^3 *logn) TC         // O(unique elements) SC
            int n=nums.size();
            set<vector<int>>s;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++){
                        if(nums[i]+nums[j]+nums[k]==0){
                            vector<int>triplet={nums[i],nums[j],nums[k]};
                            sort(triplet.begin(),triplet.end());
                            if(!s.count(triplet)){
                                s.insert(triplet);
                                ans.push_back(triplet);
                            }
                        }
                    }
                }
            }
            return ans;
        }

        vector<vector<int>> threeSumBetterApproach(vector<int>& nums){
            int n=nums.size();
            vector<vector<int>>ans;

            set<vector<int>>triplets;

            for(int i=0;i<n;i++){
                int target=-nums[i];
                unordered_set<int>s;

                for(int j=i+1;j<n;j++){
                    int tofind=target-nums[j];
                    if(s.count(tofind)){
                        vector<int>triplet={tofind,nums[j],-target};
                        sort(triplet.begin(),triplet.end());
                        if(!triplets.count(triplet)){
                            triplets.insert(triplet);
                            ans.push_back(triplet);
                        }
                    }
                    s.insert(nums[j]);
                }
            }
            return ans;
        }

        vector<vector<int>> threeSum(vector<int>& nums){ //optimal     //O(n^2 +nlogn)
            int n=nums.size();
            vector<vector<int>>ans;

            sort(nums.begin(),nums.end());

            for(int i=0;i<n;i++){
                int j=i+1;
                int k=n-1;
                if(i>0 && nums[i]==nums[i-1]){
                    continue;
                }

                while(j<k){
                    int sum=nums[i]+nums[j]+nums[k];

                    if(sum<0){
                        j++;
                    }
                    else if(sum>0){
                        k--;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[k]});
                        j++; 
                        k--;
                        while(j<k && nums[j]==nums[j-1]){
                            j++;
                        }
                    }
                }
            }
            return ans;
        }
};  