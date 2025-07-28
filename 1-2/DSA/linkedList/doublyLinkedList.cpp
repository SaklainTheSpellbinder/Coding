#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        data=val;
        next=prev=NULL;
    }
};

class doublyLinkedList{
public:
    Node* head;
    Node* tail;
    doublyLinkedList(){
        head=NULL;
        tail=NULL;
    }

    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void pop_front(){
        if(head==NULL)
            cout<<"Alredy empty\n";
        else if(head->next==NULL){
            Node* temp=head;
            head=head->next;
            delete temp;
        }
        else{
            Node* temp=head;
            head=head->next;
            head->prev=NULL;
            temp->next=NULL;
            delete temp;
        }
    }

    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
};

int main(){
    doublyLinkedList dbll;
    dbll.push_front(3737); 
    dbll.push_front(37373);
    dbll.push_front(6363);
    dbll.pop_front();
    dbll.pop_front();
    dbll.pop_front();
    dbll.printList();
}