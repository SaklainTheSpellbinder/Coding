#include<iostream>
#include "stack.h"

using namespace std;

int main(){
    ListStack* ls=new ListStack();
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            ls->push(i);
            ans=max(ans,ls->size());
        }
        else if(s[i]==')'){
            ls->pop();
        }
    }
    cout<<ans<<endl;
    delete ls;
}