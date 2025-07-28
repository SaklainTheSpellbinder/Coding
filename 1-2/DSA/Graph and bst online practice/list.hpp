#ifndef LIST_HPP
#define LIST_HPP

class Node{
    public:
        int data;
        Node* next;
    Node(int data,Node* next=nullptr){
        this->data=data;
        this->next=next;
    }
};

class listiterator{
public:
    Node* curr;
    listiterator(Node* node){
        curr=node;
    }

    int& operator*() const{
        return curr->data;
    }

    listiterator& operator++(){
        curr=curr->next;
        return *this;
    }

    bool operator !=(const listiterator& other) const{
        return curr!=other.curr;
    }
};

class YourListType{
    Node* head;
    Node* tail;
public:
    YourListType(){
        head=nullptr;
        tail=nullptr;
    }

    ~YourListType(){
        Node* curr=head;
        while(curr){
            Node*temp=curr;
            curr=curr->next;
            delete temp;
        }
        head=tail=nullptr;
    }

    YourListType(const YourListType& other) {
        head=tail=nullptr;
        Node* curr=other.head;
        while(curr){
            push_back(curr->data);
            curr=curr->next;
        }
    }

    void clear(){
        Node* curr=head;
        while(curr){
            Node*temp=curr;
            curr=curr->next;
            delete temp;
        }
        head=tail=nullptr;
    }

    YourListType& operator=(const YourListType& other) {
        if(this==&other) 
            return *this;
        Node* curr=head;
        while(curr){
            Node* temp=curr;
            curr=curr->next;
            delete temp;
        }
        head=tail=nullptr;
        curr = other.head;
        while(curr){
            push_back(curr->data);
            curr=curr->next;
        }
        return *this;
    }

    void push_back(int data){
        if(!head){
            head=new Node(data);
            tail=head;
            return;
        }
        tail->next=new Node(data);
        tail=tail->next;
    }

    bool delete_item(int n){
        Node* prev=nullptr;
        Node* curr=head;
        while(curr){
            if(curr->data==n){
                if(prev)
                    prev->next=curr->next;
                else{
                    head=curr->next;
                }
                if(curr->next==nullptr){
                    tail=prev;
                }
                delete curr;
                return true;
            }
            prev=curr;
            curr=curr->next;
        }
        return false;
    }

    int size(){
        int i=0;
        Node* curr=head;
        while(curr){
            i++;
            curr=curr->next;
        }
        return i;
    }

    bool exists(int data){
        Node* curr=head;
        while(curr){
            if(curr->data==data){
                return true;
            }
            curr=curr->next;
        }
        return false;
    }

    listiterator begin() const{
        return listiterator(head);
    }

    listiterator end() const{
        return listiterator(nullptr);
    }
};

#endif