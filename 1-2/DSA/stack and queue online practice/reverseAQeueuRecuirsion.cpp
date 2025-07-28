#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);
void reverse_queue(queue<int>&q){
    if(q.empty()){
        return;
    }
    int t=q.front();
    q.pop();
    reverse_queue(q);
    q.push(t);
}

void sortAqueue(){
    
}

int main() {
    FAST_IO;
    queue<int>q;
    for(int i=0;i<10;i++){
        q.push(i);
    }
    reverse_queue(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}