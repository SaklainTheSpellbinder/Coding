#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int longestcommonsubstringlength(string str1,string str2){
    int n=str1.size();
    int m=str2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    int ans=0;
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=0;//zero na korle to aager gula o add hoye jabe....substring pabo na...shob substring er length er jogfol pabo
            ans=max(ans,dp[i][j]);
        }        
    }
    return ans;
}

string longestcommonsubstring(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLen = 0; // Maximum length of common substring
    int endIndex = 0; // Ending index of the longest common substring in str1

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndex = i - 1; // Update the ending index
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // Extract the longest common substring
    return str1.substr(endIndex - maxLen + 1, maxLen);
}

int main(){
    string str1="abcde";
    string str2="abcge";
    cout<<longestcommonsubstringlength(str1,str2)<<endl;
}