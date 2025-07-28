#include<iostream>
#include<vector>

using namespace std;

int getMinDif(vector<int>nums){
    int totsum=0;
    for(auto it:nums){
        totsum+=it;
    }
    int n=nums.size();
    int w=totsum/2;

    vector<vector<int>>dp(n+1,vector<int>(w+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(nums[i-1]<=j){
                int ans1=dp[i-1][j-nums[i-1]]+nums[i-1];
                int ans2=dp[i-1][j];
                dp[i][j]=max(ans1,ans2);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int ans=totsum-dp[n][w];
    ans=abs(ans-dp[n][w]);
    return ans;
}

int main(){
    vector<int>nums={1,2,3};
    cout<<getMinDif(nums)<<endl;
    return 0;
}