#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
    T data;
    Node<T>* next;

    Node(T data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        cout<<"Destructing the node of "<<data<<endl;
        //jehetu kono dynamically allocated memonry nai....tai kichu kora lagtese na actually....karon ja ase oita auto delete hoye jabe....next ke NULL kore dewa holo just...
        next=NULL;
    }
};

template<typename T>
class List{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    List(){
        head=NULL;
        tail=NULL;
    }

    ~List(){
        cout<<"Destructor of list\n";
        Node<T>* current=head;
        while(current!=NULL){//first to last er dike delete kore....
            Node<T>* temp=current;
            current=current->next;//current porer tay pathay dey...
            delete temp;//ekhon je node e ache oita delete kore dey
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
            head=newNode;
        }
    }

    void push_back(T val){
        Node<T>* newNode= new Node<T>(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void printList(){
        Node<T>* curr=head;
        while(curr!=NULL){
            cout<<curr->data<<"->";
            curr=curr->next;
        }
        cout<<"NULL"<<endl;
    }

    void insert(T val,int pos){
        Node<T>* newNode=new Node<T>(val);
        Node<T>* temp=head;
        if(pos==0){
            newNode->next=head;
            if(head==NULL){
                tail=newNode;
            }
            head=newNode;
            return;
        }

        int i=0;
        while(i<pos-1){
            if(temp==NULL){
                cout<<"Position is invalid\n";
                return;
            }
            temp=temp->next;
            i++;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        if(newNode->next==NULL){
            tail=newNode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout<<"Already empty\n";
            return;
        }
        Node<T>* temp=head;
        head=head->next;
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
        Node<T>*temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
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

    void reverse(){
        Node<T>* prev=NULL;
        Node<T>* curr=head;
        while(curr!=NULL){
            Node<T>*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        tail=head;
        head=prev;
    }

    int sizeLL(){
        int i=0;
        Node<T>* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            i++;
        }
        return i;
    }

    bool isCycle(){
        Node<T>* slow=head;
        Node<T>* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                cout<<"Cycle exists\n";
                return true;
            }
        }

        cout<<"Cycle doesn't exist\n";
        return false;
    }

    void breakcycle(){
        Node<T>* slow=head;
        Node<T>* fast=head;

        bool isCycle=false;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;

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
                    fast=fast->next;
                    slow=slow->next;
                }
                fast->next=NULL;
            }
        }
    }
};



int main(){
    List<int> l;

    cout << "\n [1] Push front & back:\n";
    l.push_back(3);
    l.push_back(5);
    l.push_front(1);
    l.printList();  // Expected: 1->3->5->NULL

    cout << "\n [2] Insert at position:\n";
    l.insert(2, 1);     // Insert 2 at index 1
    l.insert(10, 100);  // Invalid pos
    l.printList();      // Expected: 1->2->3->5->NULL

    cout << "\n [3] Search:\n";
    cout << "Index of 3: " << l.searchitr(3) << endl;   // Expected: 2
    cout << "Index of 42: " << l.searchitr(42) << endl; // Expected: -1

    cout << "\n [4] Pop front & back:\n";
    l.pop_front();  // Remove 1
    l.pop_back();   // Remove 5
    l.printList();  // Expected: 2->3->NULL

    cout << "\n [5] Reverse the list:\n";
    l.reverse();
    l.printList();  // Expected: 3->2->NULL

    cout << "\n [6] List size:\n";
    cout << "Size = " << l.sizeLL() << endl;  // Expected: 2

    cout << "\n [7] Check for cycle:\n";
    l.isCycle(); // Should print: Cycle doesn't exis
}