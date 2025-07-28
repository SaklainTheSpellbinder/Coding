#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(T data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

    ~Node(){
        cout<<"Destructing the node of "<<data<<endl;
        next=NULL;
        prev=NULL;
    }
};

template<typename T>
class List{
    Node<T>* head;
    Node<T>* tail;
public:
    List(){
        head=NULL;
        tail=NULL;
    }

    ~List(){
        cout<<"Destructor of list:\n";
        Node<T>* current=head;
        while(current!=NULL){
            Node<T>* temp=current;
            current=current->next;
            delete temp;
        }
        head=NULL;
        tail=NULL;
    }

    void push_front(T val){
        Node<T>* newNode= new Node<T>(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void push_back(T val){
        Node<T>* newNode=new Node<T>(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout<<"LL is empty\n";
            return;
        }
        Node<T>* temp=head;
        head=head->next;
        if(head!=NULL){
            head->prev =NULL;
        }
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){
        if(head==NULL){
            cout<<"LL is empty\n";
            return;
        }
        if(head==tail){
            delete head;
            head=tail=NULL;
            return;
        }

        Node<T>* temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;
        delete temp;
    }

    void insert(T val,int pos){
        Node<T>* newNode=new Node<T>(val);
        Node<T>* temp=head;
        if(pos==0){
            newNode->next=head;
            if(head!=NULL){
                head->prev=newNode;
            }
            else{
                tail=newNode;
            }
            head=newNode;
            return;
        }
        int i=0;
        while(i<pos-1){
            if(temp==NULL){
                cout<<"Position invalid\n";
                return;
            }
            temp=temp->next;
            i++;
        }
        newNode->next=temp->next;
        if(temp->next!=NULL){
            temp->next->prev=newNode;
        }
        else{
            tail=newNode;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }

    int searchitr(T key){
        Node<T>* temp=head;
        int i=0;
        while(temp!=NULL){
            if(temp->data==key){
                return i;
            }
            temp=temp->next;
            i++;
        }
        return -1;
    }

    int searchrechelper(Node<T>* node,T key,int idx){
        if(!node){
            return -1;
        }
        if(node->data==key){
            return idx;
        }
        return searchrechelper(node->next,key,idx+1);
    }

    int searchrec(T key){
        return searchrechelper(head,key,0);
    }

    int sizeLL() {
        int size = 0;
        Node<T>* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            size++;
        }
        return size;
    }

    void reverse() {
        Node<T>* temp = NULL;
        Node<T>* curr = head;
    
        while (curr != NULL) {
            temp = curr;
            swap(curr->prev, curr->next);
            curr = curr->prev;
        }
    
        if (temp != NULL) {
            tail = head;
            head = temp;
        }
    }
    

    void printList(){
        Node<T>* curr=head;
        cout<<"NULL <-> ";
        while(curr!=NULL){
            cout<<curr->data<<" <-> ";
            curr=curr->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    List<int> intList;      // Linked list of integers
    intList.push_front(25);
    intList.push_front(6);
    intList.push_front(1);
    intList.push_back(289);
    intList.push_back(18);
    intList.printList();    // Should print: 1 <-> 6 <-> 25 <-> 289 <-> 18 <-> NULL

    List<string> strList;   // Linked list of strings
    strList.push_front("Hello");
    strList.push_back("World");
    strList.printList();    // Should print: Hello <-> World <-> NULL

    return 0;
}