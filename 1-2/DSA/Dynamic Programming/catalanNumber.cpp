#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int catalanRec(int n){
    if(n==0||n==1)
        return 1;
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=catalanRec(i)*catalanRec(n-1-i);
    }

    return ans;
}

int catalantab(int n){//O(n^2)
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<n+1;i++){
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-1-j];
        }
    }
    return dp[n];
}

long long catalan(int n) {//O(n)
    long  long result = 1;
    for (int i = 0; i < n; i++) {
        result = result * (2 * n - i) / (i + 1);
    }
    return result / (n + 1);
}

long long catalanSak(int n){
    long long result=1;
    for(int i=1;i<=n;i++){
        result=(result*(2*(2*i-1)))/(i+1);
    }
    return result;
}

int main(){
    cout<<catalan(4)<<endl;
    cout<<catalanRec(4)<<endl;
    cout<<catalantab(4)<<endl;
    cout<<catalanSak(4)<<endl;
}