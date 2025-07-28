#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int unboundedknapsack(vector<int>val,vector<int>wt,int w,int n){//O(n*w  )
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            int itemwt=wt[i-1];
            int itemval=val[i-1];
            if(itemwt<=j){
                //include
                int ans1= dp[i][j-itemwt]+itemval;
                //exclude
                int ans2= dp[i-1][j];
                dp[i][j]= max(ans1,ans2);
            }
            else{
                //exclude
                dp[i][j]= dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int main(){
    vector<int>val={15,14,10,45,30};
    vector<int>wt={2,5,1,3,4};
    int w=7;
    cout<<unboundedknapsack(val,wt,w,5);
    
    return 0;  
}