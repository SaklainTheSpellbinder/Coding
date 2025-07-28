//leetcode 72
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int minDistance(string word1,string word2){
    int n=word1.size();
    int m=word2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<n+1;i++){
        dp[i][0]=i;
    }

    for(int j=1;j<m+1;j++){
        dp[0][j]=j;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    return dp[n][m];
}

int main(){
    string word1="horse";
    string word2="ros";
    cout<<minDistance(word1,word2);
}