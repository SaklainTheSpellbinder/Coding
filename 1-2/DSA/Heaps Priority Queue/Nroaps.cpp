#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

void cutNropas(vector<int>roaps){
    priority_queue<int,vector<int>,greater<int>>pq(roaps.begin(),roaps.end());
    int ans=0;
    while(pq.size()>1){
        int min1=pq.top();
        pq.pop();
        int min2=pq.top();
        pq.pop();
        ans+=(min1+min2);
        pq.push(min1+min2);
    }
    cout<<"min cost: "<<ans<<endl;
}

int main(){
    vector<int>roaps={4,3,2,6};
    cutNropas(roaps);
}