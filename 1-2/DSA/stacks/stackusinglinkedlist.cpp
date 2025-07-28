#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

//create stack using linked list
template<class T>
class stack{
    list<T>ll;
    public:
    void push(T val){
        ll.push_front(val);
    }
    void pop(){
        ll.pop_front();
    }
    T top(){
        return ll.front();
    }
    bool isempty(){
        return ll.size()==0;
    }
};

int main(){
    stack<int>s;
    s.push(3);
    s.push(2);
    s.push(1);
    for(int i=0;i<3;i++){
        cout<<s.top()<<endl;
        s.pop();
    }
}