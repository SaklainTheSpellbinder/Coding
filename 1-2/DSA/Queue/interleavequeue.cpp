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
        queue<int>og;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            og.push(x);
        }
        queue<int>nokol;
        int p=ceil(n/2);
        for( int i=0;i<p;i++){
            int data=og.front();
            og.pop();
            og.push(data);
        }
        for(int i=0;i<(n/2);i++){
            nokol.push(og.front());
            og.pop();
        }
        for(int i=0;i<p;i++){
            og.push(og.front());
            og.pop();
            if(!nokol.empty()){
                og.push(nokol.front());
                nokol.pop();
            }
        }
        while(!og.empty()){
            cout<<og.front()<<" ";
            og.pop();
        }
        cout<<endl;
    }
    return 0;
}