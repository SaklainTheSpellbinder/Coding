#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

void solve(){
    vector<int>arr={2,1,1,3,3,2,2,4,4,3,3,1,1};
    int si=0;
    int ei=arr.size()-1;
    while(si<=ei){
        int mid=si+(ei-si)/2;
        if((mid==0 || arr[mid]!=arr[mid-1]) && (mid==arr.size()-1 || arr[mid]!=arr[mid+1])){
            cout<<arr[mid]<<endl;
            return;
        }
        else if(arr[mid]==arr[mid+1]){
            si=mid+2;
        }
        else if(arr[mid]==arr[mid-1]){
            ei=mid-2;
        }
    }
}

int main() {
    FAST_IO;
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}