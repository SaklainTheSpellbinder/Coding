#include<iostream>
#include<queue>
using namespace std;

int main(){
    // priority_queue<int,vector<int>,greater<int>>pq; //greater er eta na dile hocche descending order e print hoy
    // pq.push(5);
    // pq.push(10);
    // pq.push(9);
    // pq.push(7);
    // pq.push(3);
    priority_queue<string,vector<string>,greater<string>>pq;
    pq.push("alpha");
    pq.push("kukur");
    pq.push("chagol");
    pq.push("bhutto");

    while(!pq.empty()){
        cout<<"top: "<<pq.top()<<endl;
        pq.pop();
    }

    return 0;
} 