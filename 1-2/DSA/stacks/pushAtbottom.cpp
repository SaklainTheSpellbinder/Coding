#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

//create stack using linked list

template<class T>
class Node{
    public:
    T data;
    Node* next;
    Node(T val){
        data=val;
        next=NULL;
    }
};

template<class T>
class stack{
    Node<T>* head;
    public:
    stack(){
        head=NULL;
    }
    void push(T val){
        Node<T>* newNode=new Node<T>(val);
        if(head==NULL){
            head=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    void pop(){
        Node<T>* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    T top(){
        return head->data;
    }
    bool isEmpty(){
        return head==0;
    }
};
template <class T>
void pushAtBack(stack<T>& s,T val){
    if(s.isEmpty()){
        s.push(val);
        return;
    }
    T temp=s.top();
    s.pop();
    pushAtBack(s,val);
    s.push(temp);
}

string reverseString(string str){
    string temp="";
    stack<char>s;
    for(auto &it: str){
        s.push(it);
    }
    while(!s.isEmpty()){
        temp+=s.top();
        s.pop();
    }
    return temp;
}

template <class T>
void reverseStack(stack<T>& s){
    if(s.isEmpty()){
        return;
    }
    T temp=s.top();
    s.pop();
    reverseStack(s);
    pushAtBack(s,temp);
}

int main(){
    stack<int>s;
    s.push(3);
    s.push(2);
    s.push(1);
    pushAtBack(s,4);
    // stack<int>p=s;
    // while(!s.isEmpty()){
    //     cout<<s.top()<<endl;
    //     s.pop();
    // }
    reverseStack(s);
    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<reverseString("Saklain")<<endl;
}