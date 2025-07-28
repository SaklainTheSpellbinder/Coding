#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

int lis(vector<int>arr){
    set<int>s(arr.begin(),arr.end());
    vector<int>arr2(s.begin(),s.end());
    int n=arr.size();//ascending sorted order
    int m=arr2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(arr[i-1]==arr2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}


int lis2(vector<int> arr) {
    vector<int> lisArr;
    for (int num : arr) {
        auto it = lower_bound(lisArr.begin(), lisArr.end(), num);
        if (it == lisArr.end()) {
            lisArr.push_back(num); 
        } else {
            *it = num; 
        }
    }
    return lisArr.size(); 
} 


int main(){
    vector<int>arr={50,3,10,7,40,80};
    cout<<lis(arr)<<endl;
    cout<<lis2(arr)<<endl;
}