#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int knapsack(vector<int>&val,vector<int>&wt,int i,int wtnow,int ansnow){
    if(i==val.size()){
        return ansnow;
    }
    if(wtnow+wt[i]<=7){
        int ans1=knapsack(val,wt,i+1,wtnow+wt[i],ansnow+val[i]);
        int ans2=knapsack(val,wt,i+1,wtnow,ansnow);
        return max(ans1,ans2);
    }
    else{
        return knapsack(val,wt,i+1,wtnow,ansnow);
    }
}

int knapsackmem(vector<int>&val,vector<int>&wt,int w,int n,vector<vector<int>>&dp){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }

    int itemval=val[n-1];
    int itemwt=wt[n-1];

    if(itemwt<=w){
        int ans1=knapsackmem(val,wt,w-itemwt,n-1,dp)+itemval;
        int ans2=knapsackmem(val,wt,w,n-1,dp);
        dp[n][w]=max(ans1,ans2);
    }
    else{
        dp[n][w]=knapsackmem(val,wt,w,n-1,dp);
    }
    return dp[n][w];
}

int knapsacktab(vector<int>&val,vector<int>&wt,int w,int n){
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            int itemwt=wt[i-1];
            int itemval=val[i-1];
            if(itemwt<=j){
                int ans1=dp[i-1][j-itemwt]+itemval;
                int ans2=dp[i-1][j];
                dp[i][j]=max(ans1,ans2);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int main() {
    FAST_IO;
    vector<int>val={15,14,10,45,30};
    vector<int>wt={2,5,1,3,4};
    int n=val.size();
    int w=7;
    cout<<knapsack(val,wt,0,0,0)<<endl;
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    cout<<knapsackmem(val,wt,w,n,dp)<<endl;
    cout<<knapsacktab(val,wt,w,n)<<endl;
    return 0;
}