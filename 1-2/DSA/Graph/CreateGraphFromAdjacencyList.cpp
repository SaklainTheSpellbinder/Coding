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
        /*
        1. list<int>* l;
        list<int>: This is a standard container in C++ (from the STL), which implements a doubly linked list. Each element of the list is of type int in this case.

        *l: This declares a pointer l that can point to an array of list<int>. However, at this point, l is just a pointer, and it doesn't point to any valid memory yet. It's like reserving a space to hold the address of a list array, but the array itself hasn't been created yet.

        2. l = new list<int>[V];
        new list<int>[V]: This allocates dynamic memory to hold an array of V elements, where each element is a list<int>. The value V is typically the number of vertices in a graph when this pattern is used in graph representations.

        new in C++ dynamically allocates memory on the heap, and it returns a pointer to the first element of the allocated array.

        list<int>[V] means you are creating an array of V list<int> objects.

        Assigning to l: Now l points to this dynamically allocated array. Each element of this array is a list<int>, which you can then use to store integers in each list.

        */
    }

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

        while(q.size()>0){
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

    bool HasPath(int src,int des){//O(V+E)
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
        vector<bool>vis(V,false);
        return isCycleUndirHelper(0,vis,-1);
    }
};


int main(){
    Graph graph(7);
    //undirected
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    //graph.addEdge(5,6);
    graph.bfs();
    graph.dfs();

    cout<<graph.HasPath(1,4)<<endl;
    cout<<graph.isCycleUndir()<<endl;
    //graph.print();
}
