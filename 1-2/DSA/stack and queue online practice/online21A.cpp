#include<iostream>
#include "stack.h"

using namespace std;

int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    if(s[n]!='['){
        cout<<"-1"<<endl;
        return 0;
    }
    ListStack* ls=new ListStack();
    int i=0;
    while(i<s.size()){
        if(s[i]=='['){
            ls->push(i);
        }
        else if(s[i]==']'){
            int temp=ls->pop();
            if(temp==n){
                cout<<i<<endl;
                return 0;
            }
        }
        i++;
    }
    if(i==s.size()){
        cout<<"-1"<<endl;
    }
    delete ls;
}