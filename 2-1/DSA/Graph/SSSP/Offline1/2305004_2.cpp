#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

class Edge{
public:
    int a,b;
    ll weight; 
};

ll max(ll a,ll b){
    if(a>b)
        return a;
    else
        return b;
}

const ll NEG_INF=-1e18;

int main() {
    FAST_IO;
    int n,m;
    cin>>n>>m;
    vector<ll>dist(n+1,0);
    vector<int>parent(n+1,-1);
    vector<Edge>edges(m);
    for(int i=0;i<m;i++){
        cin>>edges[i].a>>edges[i].b>>edges[i].weight;
    }
    int x;
    for(int i=1;i<=n;i++){
        x=-1;
        for(auto e:edges){
            if(dist[e.a]+e.weight<dist[e.b]){
                dist[e.b]=max(NEG_INF,dist[e.a]+e.weight);
                parent[e.b]=e.a;
                x=e.a;
            }
        }
    }

    if(x==-1){
        cout<<-1<<endl;
    }
    else{
        for(int i=0;i<n;i++){
            x=parent[x];
        }
        vector<int>cycle;
        int v=x;
        do{
            cycle.push_back(v);
            v=parent[v];
        }while(v!=x);

        reverse(cycle.begin(),cycle.end());
        for(auto c:cycle){
            cout<<c<<" ";
        }
        cout<<endl;
    }

    return 0;
}