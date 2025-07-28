#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class Edge{
public:
    int v;
    int wt;

    Edge(int v,int wt){
        this->v=v;
        this->wt=wt;    
    }
};

void dijkstra(int src,vector<vector<Edge>>graph,int V){//O((V+E)logV)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//min heap;
    //pair(dist[v],v);
    vector<int>dist(V,INT32_MAX);
    pq.push({0,src});
    dist[src]=0;

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        for(auto e:graph[u]){
            if(dist[e.v]>dist[u]+e.wt){
                dist[e.v]=dist[u]+e.wt;
                pq.push({dist[e.v],e.v});
            }
        }           
    }

    for(int d: dist){
        cout<<d<<" ";
    }
    cout<<endl;
}

void bellmanford(vector<vector<Edge>>graph,int V,int src){
    vector<int>dist(V,INT32_MAX);
    dist[src]=0;

    for(int i=0;i<V-1;i++){
        for(int u=0;u<V;u++){
            for(auto e: graph[u]){
                if(dist[e.v]>dist[u]+e.wt){
                    dist[e.v]=dist[u]+e.wt;
                }
            }
        }
    }

    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int V=6;
    vector<vector<Edge>>graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(5,5));
    dijkstra(0,graph,V);
    bellmanford(graph,V,0);
}