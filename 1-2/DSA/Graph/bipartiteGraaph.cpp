#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class Graph{
    int V;
    list<int>* l;
    bool isUndir;
public:
    Graph(int V,bool isUndir=true){
        this->V=V;
        l=new list<int>[V];
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


    void addEdge(int u,int v){
        l[u].push_back(v);
        if(isUndir)
            l[v].push_back(u);
    }

    void print(){
        for(int u=0;u<V;u++){
            list<int>neighbours=l[u];
            cout<<u<<":";
            for(auto it: neighbours){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }

    void bfsHelper(int st,vector<bool>&vis){
        queue<int>q;
        q.push(st);
        vis[st]=true;

        while(!q.empty()){
            int u=q.front();
            q.pop();
            cout<<u<<" ";
            list<int>neighbours=l[u];
            for(auto& v: neighbours){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }

    void bfs(){
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bfsHelper(i,vis);
            }
        }
    }

    void dfsHelper(int u,vector<bool>&vis){
        vis[u]=true;
        cout<<u<<" ";
        list<int>neighbours=l[u];
        for(auto & it: neighbours){
            if(!vis[it]){
                dfsHelper(it,vis);
            }
        }
    }

    void dfs(){
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsHelper(i,vis);
                cout<<endl;
            }
        }
        //cout<<endl;
    }

    bool hasPathHelper(int src,int des,vector<bool>&vis){
        if(src==des)
            return true;
        vis[src]=true;
        list<int>neighbours=l[src];

        for(auto & v: neighbours){
            if(!vis[v]){
                if(hasPathHelper(v,des,vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool HasPath(int src,int des){//O(V+E)  wroks for both directed and undirected
        vector<bool>vis(V,false);
        return hasPathHelper(src,des,vis);
    }

    bool isCycleUndirHelper(int src,vector<bool>&vis,int par){
        vis[src]=true;
        list<int>neighbours=l[src];
        for(auto v: neighbours){
            if(!vis[v]){
                if(isCycleUndirHelper(v,vis,src))
                    return true;
            }
            else{
                if(v!=par)
                    return true;
            }
        }
        return false;
    }

    bool isCycleUndir(){
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycleUndirHelper(i, vis, -1))
                    return true;
            }
        }
        return false;
    }

    bool isCycleDirHelper(int src,vector<bool>&vis,vector<bool>&recPath){
        vis[src]=true;
        recPath[src]=true;

        list<int>neighbours=l[src];
        for(auto& v: neighbours){
            if(!vis[v]){
                if(isCycleDirHelper(v,vis,recPath))
                    return true;
            }
            else{
                if(recPath[v])
                    return true;
            }
        }
        recPath[src]=false;
        return false;
    }

    bool isCycleDir(){
        vector<bool>vis(V,false);
        vector<bool>recPath(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycleDirHelper(i,vis,recPath))
                    return true;
            }
        }
        return false;
    }

    bool isBipartite(){
        vector<bool>vis(V,false);
        queue<int>q;
        vector<int>color(V,-1);
        q.push(0);
        vis[0]=true;
        color[0]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:l[u]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                    color[v]=(color[u]==0)?1:0;
                }
                else{
                    if(color[v]==color[u])
                        return false;
                }
            }
        }
        return true;
    }

    int shortestPathLengthUnweighted(int src, int dest) {
        vector<int> dist(V, -1);
        queue<int> q;
        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : l[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return dist[dest]; // Returns -1 if unreachable
    }
};


int main(){
    Graph graph(5);
    //undirected
    graph.addEdge(0,1);
    graph.addEdge(1,3);
    graph.addEdge(3,4);
    graph.addEdge(2,4);
    graph.addEdge(0,2);
    // graph.bfs();
    // graph.dfs();
    // graph.print();
    cout<<graph.isBipartite()<<endl;
}
