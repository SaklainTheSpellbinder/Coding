#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

void printsubsets(string str,string subset){
    if(str.size()==0){
        cout<<subset<<"\n";
        return;
    }
    char ch=str[0];
    printsubsets(str.substr(1,str.size()-1),subset+ch);
    printsubsets(str.substr(1,str.size()-1),subset);
}

void printbitwisesubset(string str){
    int n=str.size();
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                cout<<str[i];
            }
        }
        cout<<"\n";
    }
}

int main(){
    string s="Saklain";
    printsubsets(s,"");
    printbitwisesubset(s);
}