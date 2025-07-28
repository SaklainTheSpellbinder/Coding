#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);



bool solve(){
    int n,b,m;
    cin>>n>>b;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>m;
    int k=n/b;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            if(i%k==0){
                if((i+1)%k==0 || arr[i+1]!=2){
                    count++;
                }
            }
            else{
                if(arr[i-1]!=1 && arr[i-1]!=2 && ((i+1)%k==0 || arr[i+1]!=2)){
                    count++;
                }
            }
        }
        
    }
    if(count>=m){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    FAST_IO;
    freopen("input.txt","r",stdin);
    freopen("output2.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        if(solve()){
            cout<<"true"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
    }
    return 0;
}