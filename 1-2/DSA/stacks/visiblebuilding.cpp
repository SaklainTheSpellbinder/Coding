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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        stack<int>s;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            s.push(x);
        }
        int highest=s.top();
        cout<<highest<<" ";
        while(!s.empty()){
            if(s.top()>highest){
                highest=s.top();
                cout<<highest<<" ";
            }
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}