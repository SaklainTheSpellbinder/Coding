#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int>pq(nums.begin(),nums.end());        
    int i=0;
    int ans=-1;
    while(!pq.empty() && i<k){
        ans=pq.top();
        pq.pop();
        i++;
    }
    return ans;
}

int findKthlargest(vector<int>& nums,int k){
    int maximum=*max_element(nums.begin(),nums.end());
    int minimum=*min_element(nums.begin(),nums.end());

    vector<int>count(maximum-minimum+1);
    for(int num:nums){
        count[num-minimum]++;
    }

    int res=0;
    for(int i=count.size()-1;i>=0;i--){
        res+=count[i];
        if(res>=k){
            return i+minimum;
        }
    }
    return -1;
}

int main() {
    FAST_IO;
    
    return 0;
}