#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int rob(vector<int>& nums) {
    int n=nums.size();
    vector<int>dp(n+1,0);
    dp[1]=nums[0];
    if(n==1)
        return dp[1];
    if(n==0)
        return 0;
    for(int i=2;i<=n;i++){
        dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
    }
    return dp[n];
}

int main(){
    vector<int>arr={2,7,9,3,1};
    cout<<rob(arr)<<endl;
}