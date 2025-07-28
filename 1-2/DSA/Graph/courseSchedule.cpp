#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
    public:

    bool isCycle(int src,vector<bool>&vis,vector<bool>&recPath,vector<vector<int>>& graph){
        vis[src]=true;
        recPath[src]=true;

        for(int i=0;i<graph.size();i++){
            int u=graph[i][1];
            int v=graph[i][0];

            if(u==src){
                if(!vis[v]){
                    if(isCycle(v,vis,recPath,graph))
                        return true;
                }
                else{ 
                    if(recPath[v])
                        return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }

        bool canFinish(int numCourses, vector<vector<int>>& graph) {
            int V=numCourses;
            vector<bool>vis(V,false);
            vector<bool>recPath(V,false);
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    if(isCycle(i,vis,recPath,graph))
                        return false;
                }
            }
            return true;
        }
    };


    /*
    class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& state, int src) {
        if (state[src] == 2) return true; // Cycle detected
        if (state[src] == 1) return false; // Node already processed

        state[src] = 2; // Mark as visiting
        for (int neighbor : adj[src]) {
            if (dfs(adj, state, neighbor)) return true;
        }
        state[src] = 1; // Mark as processed
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // Adjacency list
        for (auto& pair : prerequisites) {
            if (pair[0] == pair[1]) return false; // Self dependency
            adj[pair[1]].push_back(pair[0]); // Build the graph
        }

        vector<int> state(numCourses, 0); // State array: 0-unvisited, 1-processed, 2-visiting
        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0 && dfs(adj, state, i)) return false; // Cycle detected
        }
        return true; // No cycle detected
    }
};
    */