#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

void sortinstack(queue<int>&q,stack<int>&s){
    if(q.empty()){
        return;
    }
    if(s.empty() || s.top()>=q.front()){
        s.push(q.front());
        q.pop();
        return;
    }
    int data=s.top();
    s.pop();
    sortinstack(q,s);
    s.push(data);
}

void sortqueue(queue<int>&q){
    stack<int>s;
    while(!q.empty())
        sortinstack(q,s);
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

int main() {
    FAST_IO;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        queue<int>q;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            q.push(x);
        }
        sortqueue(q);
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
    }
    return 0;
}