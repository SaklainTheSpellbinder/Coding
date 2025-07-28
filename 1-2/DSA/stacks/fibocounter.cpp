#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

void fibocount(stack<int>&s,int& count){
    if(s.top()==1 || s.top()==2){
        cout<<s.top()<<" found now returning, count: "<<count<<endl;
        return;
    }
    int data=s.top();
    cout<<s.top()<<" now on top"<<endl;
    count++;
    s.push(data-1);
    cout<<s.top()<<" pushed because of "<<data<<", count: "<<count<<endl;
    fibocount(s,count);
    cout<<s.top()<<" parent: "<<data<<" now returning, count: "<<count<<endl;
    s.pop();
    count++;
    s.push(data-2);
    cout<<s.top()<<" pushed because of "<<data<<", count: "<<count<<endl;
    fibocount(s,count);
    cout<<s.top()<<" parent: "<<data<<" now returning, count: "<<count<<endl;
    s.pop();
    cout<<s.top()<<" which is the parent now returning, count: "<<count<<endl;
}

int main() {
    FAST_IO;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count=1;
        stack<int>s;
        s.push(n);
        fibocount(s,count);
        cout<<count<<endl;
    }
    return 0;
}