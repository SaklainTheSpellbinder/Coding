#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int knapsackRec(vector<int>val,vector<int>wt,int w,int n){//O(2^n)

    if(n==0 || w==0)
        return 0;

    int itemwt=wt[n-1];
    int itemval=val[n-1];
    
    if(itemwt<=w){
        //include
        int ans1= knapsackRec(val,wt,w-itemwt,n-1)+itemval;
        //exclude
        int ans2= knapsackRec(val,wt,w,n-1);
        return max(ans1,ans2);
    }
    else{
        //exclude
        return knapsackRec(val,wt,w,n-1);
    }   
}

int knapsackmem(vector<int>val,vector<int>wt,int w,int n,vector<vector<int>>&dp){//O(n*w)
    if(n==0 || w==0)
        return 0;

    if(dp[n][w]!=-1)
        return dp[n][w];
    int itemwt=wt[n-1];
    int itemval=val[n-1];
    
    if(itemwt<=w){
        //include
        int ans1= knapsackmem(val,wt,w-itemwt,n-1,dp)+itemval;
        //exclude
        int ans2= knapsackmem(val,wt,w,n-1,dp);
        dp[n][w]= max(ans1,ans2); 
        return dp[n][w];
    }
    else{
        //exclude
        dp[n][w]= knapsackmem(val,wt,w,n-1,dp);
        return dp[n][w];
    }
}

int knapsacktab(vector<int>val,vector<int>wt,int w,int n){//O(n*w  )
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            int itemwt=wt[i-1];
            int itemval=val[i-1];
            if(itemwt<=j){
                //include
                int ans1= dp[i-1][j-itemwt]+itemval;
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
    int n=5;
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    cout<<knapsacktab(val,wt,w,n)<<endl;
} 