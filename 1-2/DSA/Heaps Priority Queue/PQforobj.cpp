#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

class student{ //"<" opeator overloading
public:
    string name;
    int marks;

    student(string name,int marks){
        this->name=name;
        this->marks=marks;
    }

    bool operator < (const student &obj) const {
        return this->marks < obj.marks;   //max heap          > dile min heap hbe
    }
};

int main(){
    priority_queue<student>pq;

    pq.push(student("akib",85));
    pq.push(student("saklain",95));
    pq.push(student("oi",60));
    
    while(!pq.empty()){
        cout<<"top :"<<pq.top().name<<","<<pq.top().marks<<endl;
        pq.pop();
    }

    return 0;
}
