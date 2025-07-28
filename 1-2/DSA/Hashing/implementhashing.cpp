#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;
    Node(string key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
    }

    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

class HashTable{
    int totSize;
    int currSize;
    Node** table;

    int hashfuncton(string key){
        int idx=0;

        for(int i=0;i<key.size();i++){
            idx=idx+(key[i]*key[i])%totSize;
        }

        return idx%totSize;
    }

    void rehash(){//O(n)
        Node** oldtable=table;
        int oldsize=totSize;
        totSize=2*totSize;
        currSize=0;
        table= new Node* [totSize];

        for(int i=0;i<totSize;i++){
            table[i]=NULL;
        }

        //copy old values
        for(int i=0;i<oldsize;i++){
            Node* temp=oldtable[i];
            while(temp!=NULL){
                insert(temp->key,temp->val);
                temp=temp->next;
            }
            if(oldtable[i]!=NULL){
                delete oldtable[i];
            }
        }
    }

public:
    HashTable(int size){
        totSize=size;
        currSize=0;

        table=new Node*[totSize];

        for(int i=0;i<totSize;i++)
            table[i]=NULL;
    }

    void insert(string key,int val){//O(1) avg    worst O(n)
        int idx=hashfuncton(key);

        Node* newNode=new Node(key,val);

        newNode->next=table[idx];
        table[idx]=newNode;

        currSize++;

        double lambda=currSize/(double)totSize;
        if(lambda>1){
            rehash();
        }
    }

    bool exists(string key){
        int idx=hashfuncton(key);
        Node* temp=table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    int search(string key){
        int idx=hashfuncton(key);
        Node* temp=table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return temp->val;
            }
            temp=temp->next;
        }
        return -1;
    }

    void remove(string key){
        int idx=hashfuncton(key);

        Node* temp=table[idx];
        Node* prev=temp;
        while(temp!=NULL){
            if(temp->key==key){
                if(prev==temp)
                    table[idx]=temp->next;
                else{
                    prev->next=temp->next;
                }
                break;
            }
            prev=temp;
            temp=temp->next;
        }
    }

    void print(){

        for(int i=0;i<totSize;i++){
            cout<<"idx"<<i<<"->";
            Node* temp=table[i];
            while(temp!=NULL){
                cout<<"("<<temp->key<<","<<temp->val<<")-> ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    HashTable ht(5);

    ht.insert("India",150);
    ht.insert("China",150);
    ht.insert("US",50);
    ht.insert("Nepal",10);
    ht.insert("UK",20);

    // if(ht.exists("India")){
    //     cout<<"India population: "<<ht.search("Nepal")<<endl;
    // }
    ht.print();
    ht.remove("China");
    ht.print();
    return 0;
}