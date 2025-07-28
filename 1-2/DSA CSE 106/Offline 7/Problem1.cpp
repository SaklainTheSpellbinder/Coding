#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);



bool isPossible(vector<int>&arr,ll maxsum,int k){
    int count=1;
    ll currsum=0;
    for(int i=0;i<arr.size();i++){
        currsum+=arr[i];
        if(currsum>maxsum){
            currsum=arr[i];
            count++;
        }
        if(count>k){
            return false;
        }
    }
    return true;
}

int main() {
    FAST_IO;
    freopen("input1.txt","r",stdin);
    freopen("output11.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n<k){
            cout<<-1<<endl;
            return 0;
        }
        ll low=*max_element(arr.begin(),arr.end());
        ll high=0;
        for(int i=0;i<n;i++){
            high+=arr[i];
        }
        ll ans=high;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(isPossible(arr,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}