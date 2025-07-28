#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

class SegmentTree{
    vector<int>tree;
    int n;

    void buildTree(vector<int>&arr,int st,int ed,int node){//O(n)
        if(st==ed){
            tree[node]=arr[st];
            return;
        }

        int mid=st+(ed-st)/2;
        buildTree(arr,st,mid,2*node+1);
        buildTree(arr,mid+1,ed,2*node+2);
        tree[node]=tree[2*node+1]+tree[2*node+2];
        return;
    }

    int rangesum(int qi,int qj,int si,int sj,int node){//O(logn)
        if(qj<si || qi>sj){  //no overlap
            return 0;
        }

        if(si>=qi && sj<=qj){
            return tree[node];
        }

        int mid=si+(sj-si)/2;

        return rangesum(qi,qj,si,mid,2*node+1)+rangesum(qi,qj,mid+1,sj,2*node+2);
    }

    void updateIn(int idx,int val,int start,int end,int node){//O(logn)
        if(start==end){
            tree[node]=val;
            return;
        }

        int mid=start+(end-start)/2;
        if(idx>=start && idx<=mid){
            updateIn(idx,val,start,mid,2*node+1);
        }
        else{
            updateIn(idx,val,mid+1,end,2*node+2);
        }

        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

public:
    SegmentTree(vector<int>&arr){
        n=arr.size();
        tree.resize(4*n);
        buildTree(arr,0,n-1,0);
    }

    void printTree(){
        for(int i=0;i<tree.size();i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }

    int rangequery(int qi,int qj){
        return rangesum(qi,qj,0,n-1,0);
    }

    void updatequery(int idx,int val){
        updateIn(idx,val,0,n-1,0);
    }
};

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8};
    SegmentTree ST(arr);
    ST.printTree();
    cout<<ST.rangequery(2,5)<<endl;
    cout<<ST.rangequery(0,3)<<endl;
    cout<<ST.rangequery(6,7)<<endl;

    ST.updatequery(1,3);
    cout<<ST.rangequery(0,3)<<endl;
}