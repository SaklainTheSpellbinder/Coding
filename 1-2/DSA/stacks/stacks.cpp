#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Stack{
    vector<T>vec;
    public:
    void push(T val){ //O(1)
        vec.push_back(val);
    }

    void pop(){
        if(isEmpty()){
            cout<<"stack is empty";
            return;
        }
        vec.pop_back();
    }

    T top(){
        // if(isEmpty()){
        //     cout<<"stack is empty";
        //     return -1;
        // }
        return vec[vec.size()-1];
    }

    bool isEmpty(){
        return vec.size()==0;
    }
};


int main(){
    Stack<int>s;
    s.push(2);
    s.push(3);
    s.push(1);
    Stack<char>s;
    s.push('a');
    s.push('b');
    s.push('c');
}