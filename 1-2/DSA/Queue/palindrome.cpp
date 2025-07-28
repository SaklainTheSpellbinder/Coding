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
        queue<char>q;
        stack<char>s;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            char x;
            cin>>x;
            q.push(x);
            s.push(x);
        }
        bool is=true;
        while(!s.empty() && !q.empty()){
            if(s.top()!=q.front()){
                is=false;
                break;
            }
            s.pop();
            q.pop();
        }
        if(is){
            cout<<"True"<<endl;
        }
        else{
            cout<<"False"<<endl;
        }

    }
    return 0;
}