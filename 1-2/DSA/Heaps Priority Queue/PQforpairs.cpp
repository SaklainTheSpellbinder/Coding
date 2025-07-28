// #include<iostream>
// #include<queue>
// #include<algorithm>
// #include<vector>

// using namespace std;



// int main(){
//     priority_queue<pair<string,int>>pq;

//     pq.push(make_pair("akib",85));
//     pq.push({"saklain",95});
//     pq.push(make_pair("oi",60));
    
//     while(!pq.empty()){
//         cout<<"top :"<<pq.top().first<<","<<pq.top().second<<endl;
//         pq.pop();
//     }

//     return 0;
// }

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct ComparePair{
    bool operator () (pair<string,int>&p1,pair<string,int>&p2){
        return p1.second<p2.second;
    }
};

int main() {
    priority_queue<pair<string, int>,vector<pair<string,int>>,ComparePair> pq;

    pq.emplace("akib", 85);
    pq.emplace("saklain", 95);
    pq.emplace("oi", 60);

    while (!pq.empty()) {
        cout << "top: " << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}
