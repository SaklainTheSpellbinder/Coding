#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int knapsackRobber(vector<int>&nums,vector<int>&weight,int w){
    int n=nums.size();
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int j=0;j<=w;j++){
        if(weight[0]<=j){
            dp[1][j]=nums[0];
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(weight[i-1]<=j){
                dp[i][j]=max(dp[i-2][j-weight[i-1]]+nums[i-1],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    int i=n,j=w;
    while(i>0 && j>0){
        if(dp[i][j]==dp[i-1][j]){
            i--;
        }
        else{
            cout<<nums[i-1]<<" ";
            j-=weight[i-1];
            i-=2;
        }
    }
    cout<<endl;

    return dp[n][w];
}

int main() {
    FAST_IO;
    vector<int>nums={60,100,180,100};
    vector<int>weight={10,20,30,20};
    cout<<knapsackRobber(nums,weight,50)<<endl;
    return 0;
}