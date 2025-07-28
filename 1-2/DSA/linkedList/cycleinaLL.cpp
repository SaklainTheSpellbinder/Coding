#include<iostream>
#include<algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class List{
    public:
    Node* head;
    Node* tail;
    List(){
        head=NULL;
        tail=NULL;
    }

    void push_front(int val){
        Node* newNode=new Node(val);
        //Node* newNode(val);  eta static func theke ber holei shesh hoye jabe...tai dynamically allocate kora lagbe
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode; 
        }
    }

    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

    void insert(int val,int pos){
        Node* newNode=new Node(val);
        Node* temp=head;
        if(pos==0){
            newNode->next=head;
            head=newNode;
            return;
        }
        int i=0;
        while(i<pos-1){
            if(temp==NULL){
                cout<<"position invalid\n";
                return;
            }
            temp=temp->next;
            i++;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }

    void pop_front(){
        if(head==NULL){
            cout<<"LL is empty\n";
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp=head;
        while(temp->next->next != NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }

    int searchitr(int key){
        Node* temp=head;
        int i=0;
        /*
            while(temp!=NULL){
            if(temp->data== key){
                return i;
            }
                temp=temp->next;
                i++;
            }
            return -1;
        */
        while(temp->data!=key){
            i++;
            if(temp->next==NULL){
                cout<<"Not Found\n";
                return -1;
            }
            temp=temp->next;
        }
        return i;
    }

    int helper(Node* temp,int key){
        if(temp==NULL)
            return -1;
        if(temp->data==key){
            return 0;
        }
        int idx=helper(temp->next,key);
        if(idx==-1)
            return -1;
        return idx+1;
    }

    int searchrec(int key){
        return helper(head,key);
    }

    void reverse(){
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        tail=head;
        head=prev;
    }

    int sizeLL(){
        int size=0;
        Node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        return size;
    }

    void removeNthFromLast(int n){
        int size=sizeLL();
        int dest=size-n;
        if(dest==0){
            pop_front();
            return;
        }
        int i=1;
        Node* prev=head;
        while(i<dest){
            prev=prev->next;
            i++;
        }
        Node* temp=prev->next;
        cout<<"Going to delete: "<<temp->data<<endl;
        prev->next=prev->next->next;
        temp->next=NULL;
        delete temp;
    }
    
};
bool isCycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            cout<<"cycle exists\n";
            return true;
        }
    }
    cout<<"cycle not found\n";
    return false;
}

void removecycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    bool isCycle=false;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            isCycle=true;
            break;
        }
    }
    if(isCycle){
        slow=head;
        if(slow==fast){
            while(fast->next!=slow){
                fast=fast->next;
            }
            fast->next=NULL;
        }
        else{
            while(fast->next!=slow->next){
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=NULL;
        }
    }

}

int main(){
    List LL;
    LL.push_front(25);
    LL.push_front(6);
    LL.push_front(1);
    //1->6->25->NULL
    LL.tail->next=LL.head;
    isCycle(LL.head);
    removecycle(LL.head);
    isCycle(LL.head);
    LL.printList();
    return 0;
}

