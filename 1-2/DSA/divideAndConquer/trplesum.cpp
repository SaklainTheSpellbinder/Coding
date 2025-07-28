#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

void triplesum(vector<int>&arr, int si,int ei,int& maximum){
    if(ei-si<2){
        return;
    }
    int mid=si+(ei-si)/2;
    int sum=arr[mid-1]+arr[mid]+arr[mid+1];
    maximum=max(sum,maximum);
    triplesum(arr,si,mid,maximum);
    triplesum(arr,mid+1,ei,maximum);
}

void solve(){
    vector<int>arr={3,-1,2,10,-12,14,-4,6,8};
    int maximum=0;
    triplesum(arr,0,arr.size()-1,maximum);
    cout<<maximum<<endl;
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