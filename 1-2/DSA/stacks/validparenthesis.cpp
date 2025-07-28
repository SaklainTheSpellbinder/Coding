#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool validParenthesis(string str){
    stack<char>s;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        switch(ch){
            case '(':
            case '{':
            case '[':
                s.push(ch);
                break;
            case ')':
            {
                if(s.empty())
                    return false;
                if(s.top()=='('){
                    s.pop();
                }
                else{
                    return false;
                }
                break;
            }

            case '}':
            {
                if(s.empty())
                    return false;
                if(s.top()=='{'){
                    s.pop();
                }
                else{
                    return false;
                }
                break;
            }

            case ']':
            {
                if(s.empty())
                    return false;
                if(s.top()=='['){
                    s.pop();
                }
                else{
                    return false;
                }
                break;
            }
        }
    }
    if(s.empty())
        return true;
    else{
        return false;
    }
}

int main(){
    string str="((((({[[[[[[[[[]]]]]]]]]})))))[{()}]([{(}])";
    if(validParenthesis(str)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}