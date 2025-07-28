#include<iostream>
#include "stack.h"

using namespace std;

int main(){
    ListStack* ls=new ListStack();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="+"){
            int b=ls->pop();
            int a=ls->pop();
            ls->push(a+b);
        }
        else if(s=="-"){
            int b=ls->pop();
            int a=ls->pop();
            ls->push(a-b);
        }
        else if(s=="*"){
            int b=ls->pop();
            int a=ls->pop();
            ls->push(a*b);
        }
        else if(s=="/"){
            int b=ls->pop();
            int a=ls->pop();
            ls->push(a/b);
        }
        else{
            ls->push(stoi(s));
        }
    }
    cout<<ls->pop()<<endl;
    delete ls;
}