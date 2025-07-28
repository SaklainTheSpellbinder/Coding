#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    FAST_IO;
    int t;
    t=1;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<int>empty(m);
        for(int i=0;i<m;i++){
            cin>>empty[i];
        }
        priority_queue<int>pq(empty.begin(),empty.end());
        int ans=0;
        while(n-- && !pq.empty()){
            int t=pq.top();
            ans+=t;
            pq.pop();
            if(t!=1){
                pq.push(t-1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}