#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

class Car{
public:
    int idx;
    int distSQ;
    Car(int idx,int distSQ){
        this->idx=idx;
        this->distSQ=distSQ;
    }

    bool operator < (const Car &obj) const{
        return this->distSQ > obj.distSQ;
    }
};

void nearbycars(vector<pair<int,int>>pos,int k){
    vector<Car>cars;

    for(int i=0;i<pos.size();i++){  //O(n)
        int distSQ=(pos[i].first)*(pos[i].first) + (pos[i].second)*(pos[i].second);
        cars.push_back(Car(i,distSQ));
    }

    priority_queue<Car>pq(cars.begin(),cars.end()); //O(n)

    for(int i=0;i<k;i++){
        cout<<"Car "<<pq.top().idx<<endl;
        pq.pop();
    }
}

int main(){
    vector<pair<int,int>>pos;
    pos.push_back({3,3});
    pos.push_back({5,-1});
    pos.push_back({-2,4});
    nearbycars(pos,2);
    int k=2;
}