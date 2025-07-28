#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int mcmRec(vector<int>arr,int i,int j){
    if(i==j)
        return 0;
    int ans=INT32_MAX;
    
    for(int k=i;k<j;k++){
        //(i,k)
        int cost1=mcmRec(arr,i,k);
        //(k+1,j)
        int cost2=mcmRec(arr,k+1,j);
        int currCost=cost1+cost2+arr[i-1]*arr[k]*arr[j];
        ans=min(ans,currCost);
    }
    return ans;
}

int mcmMem(vector<int>arr,int i,int j,vector<vector<int>>&dp){
    if(i==j)
        return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT32_MAX;

    for(int k=i;k<j;k++){
        //(i,k)
        int cost1=mcmMem(arr,i,k,dp);
        //(k+1,j)
        int cost2=mcmMem(arr,k+1,j,dp);
        int currCost=cost1+cost2+arr[i-1]*arr[k]*arr[j];
        ans=min(ans,currCost);
    }

    dp[i][j]=ans;
    return ans;

}

string buildOrder(vector<vector<int>>&s,int i,int j){
    if(i==j){
        return ("A"+to_string(i));
    }
    return "("+buildOrder(s,i,s[i][j])+"*"+buildOrder(s,s[i][j]+1,j)+")";
}

int mcmTab(vector<int>arr,int i,int j){
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    vector<vector<int>>s(n,vector<int>(n,0));
        for(int len=2;len<n;len++){
            for(int i=1;i<=n-len;i++){
                int j=i+len-1;
                dp[i][j]=INT32_MAX;
                for(int k=i;k<j;k++){
                    int cost1=dp[i][k];
                    int cost2=dp[k+1][j];
                    int currcost=cost1+cost2+arr[i-1]*arr[k]*arr[j];
                    if(currcost<dp[i][j]){
                        dp[i][j]=currcost;
                        s[i][j]=k;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<buildOrder(s,1,n-1)<<endl;
    return dp[1][n-1];
}

int main(){
    vector<int>arr={30,35,15,5,10,20,25};   // n -> n-1 matrices
    int n=arr.size();
    cout<<mcmRec(arr,1,n-1)<<endl;
    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout<<mcmMem(arr,1,n-1,dp)<<endl;
    cout<<mcmTab(arr,1,n-1);
    return 0;
}