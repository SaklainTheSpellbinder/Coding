#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int>deq;
    deq.push_front(4);
    deq.push_front(5);
    deq.push_back(3);
    deq.push_back(1);
    deq.pop_front();
    deq.pop_back();
    cout<<deq.front()<<endl;
    cout<<deq.back()<<endl;

}