#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void stockspan(vector<int>stock,vector<int>span){
    stack<int>s;
    s.push(0);
    span[0]=1;
    for(int i=1;i<stock.size();i++){
        while(!s.empty() && stock[i]>=stock[s.top()]){
            s.pop();
        }
        if(s.empty()){
            span[i]=i+1;
        }
        else{
            int prevHigh=s.top();
            span[i]=i-prevHigh;
        }
        s.push(i);
    }
    for(int i=0;i<span.size();i++){
        cout<<span[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    vector<int> stock={100,80,60,70,60,85,100};
    vector<int>span(7,0);
    stockspan(stock,span);
}