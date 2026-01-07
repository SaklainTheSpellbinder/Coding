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
    int n,m;
    cin>>n>>m;
    vector<pair<ll,int>>adj[n+1];
    priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>>pq;
    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }
    vector<vector<ll>>dist(n+1,vector<ll>(2,1e18));

    dist[1][0]=0;
    dist[0][0]=0;
    pq.push({0,{1,0}});
    while(!pq.empty()){
        ll d=pq.top().first;
        int u=pq.top().second.first;
        int state=pq.top().second.second;
        pq.pop();
        if(d>dist[u][state]) 
            continue;
        for(auto e:adj[u]){
            ll weight=e.first;
            int v=e.second;
            if(d+weight<dist[v][state]){
                dist[v][state]=d+weight;
                pq.push({dist[v][state],{v,state}});
            }
            if(state==0){
                ll low=d+(weight/2);
                if(low<dist[v][1]){
                    dist[v][1]=low;
                    pq.push({low,{v,1}});
                }
            }
        }
    }
    cout<<dist[n][1]<<endl;
    return 0;
}