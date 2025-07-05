#ifndef ADJACENCY_LIST_GRAPH_H
#define ADJACENCY_LIST_GRAPH_H

#include "GraphADT.h"
#include"list.hpp"
#include"listqueue.hpp"
#include<iostream>
#include<algorithm>
using namespace std;


class AdjacencyListGraph : public GraphADT
{
private:
    // TODO: Take necessary private members
    YourListType* l;
    int count;
    int capacity;
    int* mapping;
    int maxelement;

    void resize(int new_capacity){
        YourListType* temp=new YourListType[new_capacity];
        int* temp2=new int[new_capacity];
        for(int i=0;i<count;i++){
            temp[i]=l[i];
            temp2[i]=mapping[i];
        }
        delete[] l;
        delete[] mapping;
        l=temp;
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
    AdjacencyListGraph(){
        l=new YourListType[2];
        mapping=new int[2];
        count=0;
        capacity=2;
        maxelement=-1;
    }

    ~AdjacencyListGraph(){
        delete[] l;
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
            resize(2*capacity);
        }
        mapping[count++]=v;
        //cout<<"Node"<<v<<" added\n";
        
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
            l[x].push_back(y);
            l[y].push_back(x);
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
        return l[x].exists(y) && l[y].exists(x);
    }

    void RemoveNode(int v) override
    {
        //TODO: Remove a node.
        int x=find(v);
        if(x==-1){
            cout<<"Already doesn't exist\n";
            return;
        }
        for(auto y: l[x]){
            l[y].delete_item(x);
        }
        for(int i=x;i<count-1;i++){
            l[i]=l[i+1];
            mapping[i]=mapping[i+1];
        }
        for (int i=0;i<count-1;++i){
            for(int& idx : l[i]){
                if(idx>x) 
                    idx-=1;
            }
        }
        l[count-1].clear();
        count--;
        if((capacity/4)>count){
            resize(max(capacity/2,2));
        }
    }

    void RemoveEdge(int u, int v) override
    {
        //TODO: remove an edge
        if(CheckEdge(u,v)){
            int x=find(u);
            int y=find(v);
            l[x].delete_item(y);
            l[y].delete_item(x);
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
            for(auto vi: l[temp]){
                if(!vis[vi]){
                    q->enqueue(vi);
                    vis[vi]=true;
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
            for(auto vi: l[temp]){
                if(!vis[vi]){
                    q->enqueue(vi);
                    prev[vi]=temp;
                    vis[vi]=true;
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
            for(auto vi: l[temp]){
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
        delete q;
        delete[] dist;
        delete[] vis;
        //cout<<"More";
        return -1;
    }

    YourListType GetNeighbors(int u) const override
    {
        //TODO: Return the list of neighbors.
        YourListType lq;
        int x=find(u);
        if(x==-1){
            throw runtime_error("Node doesn't exist");
        }
        for(auto y:l[x]){
            lq.push_back(mapping[y]);
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

#endif // ADJACENCY_LIST_GRAPH_H
