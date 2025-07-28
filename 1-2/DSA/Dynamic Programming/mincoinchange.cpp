#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int minCoinChange(vector<int>&arr,int amount){
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
            if(arr[i-1]<=j && dp[i][j-arr[j-1]]!=INT_MAX){
                dp[i][j]=min(dp[i][j-arr[i-1]]+1,dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return (dp[n][amount]==INT_MAX)?-1:dp[n][amount];
}

int main() {
    FAST_IO;
    vector<int>arr={1,2,4,5,10,20,40,50,100};
    cout<<minCoinChange(arr,83)<<endl;
    return 0;
}