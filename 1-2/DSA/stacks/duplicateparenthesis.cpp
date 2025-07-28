#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool isDuplicate(string str){
    stack<char>s;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch!=')')
            s.push(ch);
        else{
            if(s.top()=='('){
                return true;
            }
            while(s.top()!='(')
                s.pop();
            s.pop();
        }
    }
    return false;
}

int main(){
    string str="(((a+b)+c))"; 
    if(isDuplicate(str)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}