#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        if(k>1 || is_sorted(v.begin(),v.end()))
        {
            cout<<"YES"<<"\n";
        }
        else
            cout<<"NO"<<"\n";
    }
    return 0;
}