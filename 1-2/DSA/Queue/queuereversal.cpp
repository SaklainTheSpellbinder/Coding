#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverse(queue<int>&org){
    stack<int>s;
    while(!org.empty()){
        s.push(org.front());
        org.pop();
    }
    while(!s.empty()){
        org.push(s.top());
        s.pop();
    }
}

int main(){
    queue<int>q;
    q.push(2);
    q.push(3);
    q.push(5);
    q.push(10);
    reverse(q);
    while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
    }
}