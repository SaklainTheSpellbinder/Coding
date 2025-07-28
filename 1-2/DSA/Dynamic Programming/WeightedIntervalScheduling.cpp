#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);
class Job{
public:
    int start;
    int finish;
    int value;
};

int binarysearch(vector<Job>&jobs,int idx){
    int low=0;
    int high=idx-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(jobs[mid].finish<=jobs[idx].start){
            if(jobs[mid+1].finish<=jobs[idx].start){
                low=mid+1;
            }
            else{
                return mid;
            }
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int weightedInterval(vector<int>&s,vector<int>&f,vector<int>&val){
    vector<Job>jobs(s.size());
    for(int i=0;i<s.size();i++){
        jobs[i].start=s[i];
        jobs[i].finish=f[i];
        jobs[i].value=val[i];;
    }
    int n=s.size();
    vector<int>dp(n);
    dp[0]=jobs[0].value;
    for(int i=1;i<n;i++){
        int now=jobs[i].value;
        int l=binarysearch(jobs,i);
        if(l!=-1){
            now+=dp[l];
        }
        dp[i]=max(now,dp[i-1]);
    }
    return dp[n-1];
}

int main() {
    FAST_IO;
    vector<int>s={1,3,6,6};
    vector<int>f={7,5,19,100};
    vector<int>val={50,190,100,200};
    cout<<weightedInterval(s,f,val)<<endl;
    return 0;
}