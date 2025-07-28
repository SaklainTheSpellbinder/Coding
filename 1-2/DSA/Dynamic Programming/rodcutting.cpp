#include<iostream>
#include<vector>
#include<string>

using namespace std;

int rodlengthmax(vector<int>&price,vector<int>&length,int rodlength){
    int n=price.size();
    vector<vector<int>>dp(n+1,vector<int>(rodlength+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<rodlength+1;j++){
            int itemprice=price[i-1];
            int itemlength=length[i-1];
            if(itemlength<=j){
                int ans1=dp[i][j-itemlength]+itemprice;
                int ans2=dp[i-1][j];
                dp[i][j]=max(ans1,ans2);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][rodlength];
}

int main(){
    vector<int>price={1,5,8,9,10,17,17,20};
    vector<int>length={1,2,3,4,5,6,7,8};
    int rodlength=8;
    cout<<rodlengthmax(price,length,rodlength);
}

