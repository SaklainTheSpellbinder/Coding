#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class Graph{
    int V;
    list<pair<int,int>>* l;
    bool isUndir;
public:
    Graph(int V,bool isUndir=true){
        this->V=V;
        l=new list<pair<int,int>>[V];
        this->isUndir=isUndir;
    }

    /*
    Graph(int V, bool isUndir = true) : V(V), isUndir(isUndir) {
        l = new list<int>[V];
    }
    */

    ~Graph() {
        delete[] l;  // Fix memory leak
    }

    // Prevent accidental copying
    Graph(const Graph&) = delete;
    Graph& operator=(const Graph&) = delete;


    void addEdge(int u,int v,int wt){
        l[u].push_back({v,wt});
        if(isUndir)
            l[v].push_back({u,wt});
    }

    void primsAlgo(int src){
        vector<bool>mst(V,false);//ekhane src true kora jabena
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        int ans=0;
        while(!pq.empty()){
            int cost=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(!mst[u]){
                mst[u]=true;
                ans+=cost;
                for(auto neigh:l[u]){
                    pq.push({neigh.second,neigh.first});
                }
            }
        }
        cout<<ans<<endl;
    }
   
};

int minCostConnectPoints(vector<vector<int>>& points) {
    int V=points.size();
    vector<bool>mst(V,false);//ekhane src true kora jabena
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int src=0;
        pq.push({0,src});
        int ans=0;
        while(!pq.empty()){
            int cost=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(!mst[u]){
                mst[u]=true;
                ans+=cost;
                for(int v=0;v<V;v++){
                    if(u!=v){
                        int wt=abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1]);
                        pq.push({wt,v});
                    }
                    
                }
            }
        }
        return ans;
}


int main(){
    Graph graph(4);
    graph.addEdge(0,1,10);
    graph.addEdge(1,3,40);
    graph.addEdge(0,2,15);
    graph.addEdge(2,3,50);
    graph.addEdge(0,3,30);
    graph.primsAlgo(0);
}
