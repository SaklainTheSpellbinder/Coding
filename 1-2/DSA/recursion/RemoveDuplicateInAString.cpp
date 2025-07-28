#include<iostream>
#include<vector>
#include<string>
using namespace std;


void removeduplicates(string s,string ans,int i,vector<bool>map){
    if(i==s.size()){
        cout<<"ans : "<<ans<<endl;
        return;
    }
    int mapidx=s[i]-'a';
    if(map[mapidx]){
        removeduplicates(s,ans,i+1,map);
    }
    else{
        map[mapidx]=true;
        removeduplicates(s,ans+s[i],i+1,map);
    }
}

void rmvdup(string s,string ans,vector<bool>map){
    if(s.size()==0){
        cout<<"ans : "<<ans<<endl;
        return;
    }
    int n=s.size();
    char ch=s[n-1];
    int mapidx=s[n-1]-'a';
    s=s.substr(0,n-1);
    if(map[mapidx]){
        rmvdup(s,ans,map);
    }
    else{
        map[mapidx]=true;
        rmvdup(s,ch+ans,map);
    }
}


int main(){
    string s="hehe";
    string ans="";
    vector<bool>map(26,false);
    removeduplicates(s,ans,0,map);
    string tingtong="";
    vector<bool>cap(26,false);
    rmvdup(s,tingtong,cap);
}