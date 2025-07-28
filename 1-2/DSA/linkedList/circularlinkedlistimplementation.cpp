#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }

    ~Node(){
        cout<<"Destructing the node with data: "<<data<<endl;
        next=prev=NULL;
    }
};

template <typename T>
class List{
    Node<T>* head;
    Node<T>* tail;
public:
    List(){
        head=NULL;
        tail=NULL;
    }


    ~List(){
        cout<<"Destructing the list: \n";
        if(head==NULL){
            return;
        }
        //beaking the cycle
        head->prev=NULL;
        tail->next=NULL;
        Node<T>* curr=head;
        while(curr!=NULL){
            Node<T>* temp=curr;
            curr=curr->next;
            temp->next=NULL;
            temp->prev=NULL;
            delete temp;
        }   
        head=NULL;
        tail=NULL;
    }

    void push_front(T val){
        Node<T>* newNode=new Node<T>(val);
        if(head==NULL){
            head=tail=newNode;
            head->next=head->prev=head;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            newNode->prev=tail;
            tail->next=newNode;
            head=newNode;
        }
    }

    void push_back(T val){
        Node<T>* newNode=new Node<T>(val);
        if(head==NULL){
            head=tail=newNode;
            head->next=head->prev=newNode;
        }
        else{
            tail->next=newNode;
            head->prev=newNode;
            newNode->prev=tail;
            newNode->next=head;
            tail=newNode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout<<"LL is empty\n";
            return;
        }
        if(head==tail){
            delete head;
            head=tail=NULL;
            return;
        }
        Node<T>* temp=head;
        head=head->next;
        tail->next=head;
        temp->next=NULL;
        temp->prev=NULL;
        head->prev=tail;
        delete temp;
    }

    void pop_back(){
        if(head==NULL){
            cout<<"LL is empty\n";
            return;
        }
        if(head==tail){
            delete tail;
            head=tail=NULL;
            return;
        }

        Node<T>* temp=tail;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        temp->next=temp->prev=NULL;
        delete temp;
    }

    void insert(T val,int pos){
        if(pos<=0 || head==NULL){
            push_front(val);
            return;
        }
        int n=sizeLL();
        if(pos>=n){
            push_back(val);
            return;
        }

        Node<T>* newNode=new Node<T>(val);
        Node<T>* temp=head;
        int i=0;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next->prev=newNode;
    }

    int searchitr(T key) {
        if (!head) return -1;
        Node<T>* temp = head;
        int idx = 0;
        do {
            if (temp->data == key) return idx;
            temp = temp->next;
            idx++;
        } while (temp != head);
        return -1;
    }

    int sizeLL() {
        if (!head) return 0;
        int count = 0;
        Node<T>* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    void reverse() {
        if (!head) return;
        Node<T>* curr = head;
        do {
            swap(curr->prev, curr->next);
            curr = curr->prev;
        } while (curr != head);
        swap(head, tail);
    }

    void printList() {
        if (!head) {
            cout << "[empty]" << endl;
            return;
        }
        Node<T>* curr = head;
        cout << "<-> ";
        do {
            cout << curr->data << " <-> ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }

    void makecircular(Node<T>* curr){
        if(curr->next==NULL){
            curr->next=head;
            return;
        }
        return makecircular(curr->next);
    }
};


int main(){
    List<int> intList;
    intList.push_front(25);
    intList.push_front(6);
    intList.push_front(1);
    intList.push_back(289);
    intList.push_back(18);
    intList.printList();  // 1 <-> 6 <-> 25 <-> 289 <-> 18 <->

    intList.reverse();    // reverse the circular list
    intList.printList();  // 18 <-> 289 <-> 25 <-> 6 <-> 1 <->

    intList.pop_front();  // remove 18
    intList.printList();

    intList.pop_back();   // remove 1
    intList.printList();

    List<string> strList;
    strList.push_front("Hello");
    strList.push_back("World");
    strList.printList();  // Hello <-> World <->

    return 0;
}