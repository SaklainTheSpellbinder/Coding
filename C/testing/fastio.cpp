#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,count=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        if(t%k==0)
            count++;
    }
    cout<<count<<"\n";
}