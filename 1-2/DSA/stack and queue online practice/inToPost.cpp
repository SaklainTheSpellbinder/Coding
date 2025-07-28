#include<iostream>
#include "stack.h"

using namespace std;

int main(){
    ListStack* ls=new ListStack();
    string s;
    cin>>s;
    string result;
    for(int i=0;i<s.size();i++){
        if(s[i]=='^'){
            ls->push(i);
        }
        else if(s[i]=='*' || s[i]=='/'){
            while(!ls->empty() && s[ls->top()]=='^')
                result+=s[ls->pop()];
            ls->push(i);
        }
        else if(s[i]=='+' || s[i]=='-'){
            while(!ls->empty() &&(s[ls->top()]=='^' || s[ls->top()]=='*' || s[ls->top()]=='/'))
                result+=s[ls->pop()];
            ls->push(i);
        }
        else if(s[i]=='(' || s[i]==')'){
            if(s[i]=='('){
                ls->push(i);
            }
            else{
                while(!ls->empty() && s[ls->top()]!='(')
                    result+=s[ls->pop()];
                ls->pop();
            }
        }
        else{
            result+=s[i];
        }
    }
    while(!ls->empty()){
        result+=s[ls->pop()];
    }
    cout<<result<<endl;
    delete ls;
}