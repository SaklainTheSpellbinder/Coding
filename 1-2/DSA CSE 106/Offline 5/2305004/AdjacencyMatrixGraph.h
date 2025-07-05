#ifndef ADJACENCY_MATRIX_GRAPH_H
#define ADJACENCY_MATRIX_GRAPH_H

#include "GraphADT.h"


class AdjacencyMatrixGraph : public GraphADT
{
private:
    //TODO: Consider necessary private members as per your discretion
    int** mat;
    int count;
    int capacity;
    int* mapping;
    int maxelement;

    void resizeMatrix(int new_capacity)
    {
        //TODO: you need to resize your matrix when you will less data or more data
        int** temp=new int*[new_capacity];
        for(int i=0;i<new_capacity;i++){
            temp[i]=new int[new_capacity];
        }
        int* temp2=new int[new_capacity];
        for(int i=0;i<count;i++){
            for(int j=0;j<count;j++){
                temp[i][j]=mat[i][j];
            }
            temp2[i]=mapping[i];
        }
        for(int i=0;i<new_capacity;i++){
            for(int j=0;j<new_capacity;j++){
                if (i >= count || j >= count) 
                temp[i][j] = 0;
            }
        }

        for(int i=0;i<capacity;i++){
            delete[] mat[i];
        }
        delete[] mat;
        delete[] mapping;
        mat=temp;
        mapping=temp2;
        capacity=new_capacity;
    }

    int find(int v) const{
        for(int i=0;i<count;i++){
            if(mapping[i]==v){
                return i;
            }
        }
        return -1;
    }

public:
    AdjacencyMatrixGraph(){
        mat=new int*[2];
        for(int i=0;i<2;i++){
            mat[i]=new int[2];
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                mat[i][j]=0;
            }
        }
        mapping=new int[2];
        capacity=2;
        count=0;
        maxelement=-1;
    }

    ~AdjacencyMatrixGraph(){
        for(int i=0;i<capacity;i++){
            delete[] mat[i];
        }
        delete[] mat;
        delete[] mapping;
    }

    void AddNode(int v) override
    {
        //TODO: Add a new node v and resize the matrix if your current matrix is almost going to be full.
        if(find(v)!=-1){
            cout<<"Node already exists\n";
            return;
        }
        if(count==capacity){
            resizeMatrix(2*capacity);
        }
        mapping[count++]=v;
    }

    void AddEdge(int u, int v) override
    {
        //TODO: Add a new edge between the nodes u and v
         int x=find(u);
        if(x==-1){
            AddNode(u);
            x=find(u);
        }
        int y=find(v);
        if(y==-1){
            AddNode(v);
            y=find(v);
        }
        if(!CheckEdge(u,v)){
            mat[x][y]=1;
            mat[y][x]=1;
            //cout<<"Edge("<<u<<", "<<v<<") added\n";
        }
        else{ 
            //cout<<"Edge ("<<u<<", "<<v<<") already exists\n";
        }
    }

    bool CheckEdge(int u, int v) const override
    {
        //TODO: Check whether there is an edge between two nodes u and v
        int x=find(u);
        int y=find(v);
        if(x==-1 || y==-1){
            return false;
        }
        return mat[x][y] && mat[y][x];
    }

    void RemoveNode(int v) override
    {
        //TODO: Remove a node.
        int x=find(v);
        if(x==-1){
            cout<<"Already doesn't exist\n";
            return;
        }
        for(int i=0;i<count;i++){
            if(mat[x][i]){
                mat[x][i]=0;
                mat[i][x]=0;
            }
        }
        for(int i=x;i<count-1;i++){
            for(int j=0;j<count;j++){
                mat[i][j]=mat[i+1][j];
            }
            mapping[i]=mapping[i+1];
        }
        
        for(int i=0;i<count-1;i++){
            for(int j=x;j<count-1;j++){
                mat[i][j]=mat[i][j+1];
            }
        }

        for(int i=0;i<count;i++){
            mat[count-1][i]=0;
            mat[i][count-1]=0;
        }
        count--;
        if((capacity/4)>count){
            resizeMatrix(max(capacity/2,2));
        }
    }

    void RemoveEdge(int u, int v) override
    {
        //TODO: remove an edge
        if(CheckEdge(u,v)){
            int x=find(u);
            int y=find(v);
            mat[x][y]=0;
            mat[y][x]=0;
        }
        else{
            cout<<"Edge doesn't exist\n";
        }
    }

    bool CheckPath(int u, int v) const override
    {
        //TODO: Return true if there is a path between nodes u and v. Otherwise return false
        int x=find(u);
        int y=find(v);
        if(x==-1 || y==-1){
            return false;
        }
        ListQueue* q=new ListQueue();
        bool* vis=new bool[count];
        for(int i=0;i<count;i++){
            vis[i]=false;
        }
        q->enqueue(x);
        vis[x]=true;
        while(!q->empty()){
            int temp=q->dequeue();
            //cout<<"Reached"<<temp<<endl;
            if(temp==y){
                delete[] vis;
                delete q;
                return true;
            }    
            for(int i=0;i<count;i++){
                if(mat[temp][i]){
                    if(!vis[i]){
                        q->enqueue(i);
                        vis[i]=true;
                    }
                }
            }
        }
        delete q;
        delete[] vis;
        return false;
    }

    void FindShortestPath(int u, int v) const override
    {
        //TODO: Find the shortest path between the nodes u and v and print it.
        int x=find(u);
        int y=find(v);
        if(x==-1 || y==-1){
            cout<<"No such node\n";
            return;
        }
        ListQueue* q=new ListQueue();
        int* prev=new int[count];
        bool* vis=new bool[count];
        for(int i=0;i<count;i++){
            prev[i]=-1;
            vis[i]=false;
        }
        q->enqueue(x);
        vis[x]=true;
        while(!q->empty()){
            int temp=q->dequeue();
            //cout<<"reached "<<temp<<endl;
            if(temp==y){
                break;
            }   
            for(int i=0;i<count;i++){
                if(mat[temp][i]){
                    if(!vis[i]){
                        q->enqueue(i);
                        prev[i]=temp;
                        vis[i]=true;
                    }
                }
            }
        }
        delete q;
        if(!vis[y]){
            cout<<"Path doesn't exist\n";
            delete[] vis;
            delete[] prev;
            return;
        }
        int* path=new int[count];
        int pathidx=0;
        for(int i=y;i!=-1;i=prev[i]){
            path[pathidx++]=mapping[i];
        }
        cout<<"Shortest path: ";
        for(int i=pathidx-1;i>=0;i--){
            cout<<path[i]<<" ";
        }
        cout<<endl;
        delete[] path;
        delete[] vis;
        delete[] prev;
    }

    int FindShortestPathLength(int u, int v) const override
    {
        //TODO: Return the shortest path length between nodes u and v if any such path exists. Otherwise return -1.
        int x=find(u);
        int y=find(v);
        if(x==-1 || y==-1){
            cout<<"No such node\n";
            return -1;
        }
        ListQueue* q=new ListQueue();
        int* dist=new int[count];
        bool* vis=new bool[count];
        for(int i=0;i<count;i++){
            dist[i]=-1;
            vis[i]=false;
        }
        q->enqueue(x);
        vis[x]=true;
        dist[x]=0;
        while(!q->empty()){
            int temp=q->dequeue();
            for(int vi=0;vi<count;vi++){
                if(mat[temp][vi]){
                    if(!vis[vi]){
                        dist[vi]=dist[temp]+1;
                        vis[vi]=true;
                        //cout<<"Reached "<<neighbor<<endl;
                        if(vi==y){
                            delete q;
                            int temp3=dist[y];
                            delete[] dist;
                            delete[] vis;
                            return temp3;
                        }
                        q->enqueue(vi);
                    }
                }
            }
        }
        delete q;
        delete[] dist;
        delete[] vis;
        //cout<<"More";
        return -1;
    }
    YourListType GetNeighbors(int u) const override
    {
        //TODO return a list of neighbors of node u
        YourListType lq;
        int x=find(u);
        if(x==-1){
            throw runtime_error("Node doesn't exist");
        }
        for(int i=0;i<count;i++){
            if(mat[x][i]){
                lq.push_back(mapping[i]);
            }
        }
        return lq;
    }

    // void print() const{
    //     for(int i=0;i<count;i++){
    //         std::cout << "Neighbors of node "<<mapping[i]<<" : ";
    //         auto neighbours = GetNeighbors(mapping[i]);
    //         for (int n : neighbours)
    //         {
    //             std::cout << n << " ";
    //         }
    //         std::cout << "\n";
    //     }
    // }

};

#endif // ADJACENCY_MATRIX_GRAPH_H
