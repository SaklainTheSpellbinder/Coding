#include<iostream>
#include "queue.h"

using namespace std;

int main(){
    ListQueue* qa=new ListQueue();
    ListQueue* qb=new ListQueue();
    ListQueue* qc=new ListQueue();
    while(true){
        string s;
        cin>>s;
        if(s=="enter"){
            int n;
            cin>>n;
            if(qb->size() <= qc->size()){
                qb->enqueue(n);
                cout<<"Customer "<<n<<" enters queue B\n";
            }
            else{
                qc->enqueue(n);
                cout<<"Customer "<<n<<" enters queue C\n";
            }
        }
        else if(s=="A" || s=="B" || s=="C"){
            string st;
            cin>>st;
            if(st=="approve"){
                if(s=="A"){
                    if(qa->empty()){
                        cout<<"Queue A wad already empty\n";
                    }
                    else{
                        int temp=qa->dequeue();
                        cout<<"Customer "<<temp<<" gets the loan\n";
                    }
                }     
                else if(s=="B"){
                    if(qb->empty()){
                        cout<<"Queue B wad already empty\n";
                    }
                    else{
                        int temp=qb->dequeue();
                        qa->enqueue(temp);
                        cout<<"Customer "<<temp<<" enters queue A\n";
                    }
                }
                else if(s=="C"){
                    if(qc->empty()){
                        cout<<"Queue C wad already empty\n";
                    }
                    else{
                        int temp=qc->dequeue();
                        qa->enqueue(temp);
                        cout<<"Customer "<<temp<<" enters queue A\n";
                    }
                }
            }
            else{
                int temp;
                if(s=="B"){
                    if(qb->empty()){
                        cout<<"Queue B wad already empty\n";
                    }
                    else{
                        temp=qb->dequeue();
                    }
                }
                else{
                    if(qc->empty()){
                        cout<<"Queue C wad already empty\n";
                    }
                    else{
                        temp=qc->dequeue();
                    }
                }
                if(qb->size() >= qc->size()){
                    qb->enqueue(temp);
                    cout<<"Customer "<<temp<<" enters queue B\n";
                }
                else{
                    qc->enqueue(temp);
                    cout<<"Customer "<<temp<<" enters queue C\n";
                }
            }
        }
        else if(s=="terminate"){
            break;
        }
        else{
            cout<<"Not a correct command\n";
        }
    }
    delete qa;
    delete qb;
    delete qc;
}