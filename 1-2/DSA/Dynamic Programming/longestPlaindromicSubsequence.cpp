#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int lps(string s){
    int n=s.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--){
        dp[i][i]=1;
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]){
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    string lpstring;
    string left="";
    string right="";
    int i=0,j=n-1;
    while(i<=j){
        if(s[i]==s[j]){
            if(i==j){
                left+=s[i];
            }
            else{
                left+=s[i];
                right=s[j]+right;
            }
            i++;
            j--;
        }
        else if(dp[i+1][j]>=dp[i][j-1]){
            i++;
        }
        else if(dp[i][j-1]>=dp[i+1][j]){
            j--;
        }
    }
    lpstring=left+right;
    cout<<lpstring<<endl;
    return dp[0][n-1];
}

int lpsubstring(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxlen = 1;
    int start = 0;
    for(int i = 0; i < n; i++)
        dp[i][i] = true;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxlen = 2;
        }
    }
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if(s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                maxlen = len;
            }
        }
    }
    cout << s.substr(start, maxlen) << endl;
    return maxlen;
}

int main() {
    FAST_IO;
    cout<<lpsubstring("bbbab");
    return 0;
}