#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool isMatch(string t,string p){
    int n=t.size();
    int m=p.size();

    vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
    dp[0][0]=true;
    for(int j=1;j<m+1;j++){//0th row
        if(p[j-1]=='*')
            dp[0][j]=dp[0][j-1];
    }

    //bottom up
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(t[i-1]==p[j-1] || p[j-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }
            else if(p[j-1]=='*'){
                dp[i][j]=dp[i][j-1] || dp[i-1][j];
            }
            else{
                dp[i][j]=false;
            }
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][m];
}

int main(){
    string t="abcd";
    string p="*b*";
    cout<<isMatch(t,p)<<endl;
}