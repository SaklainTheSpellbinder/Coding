#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<set>

using namespace std;

int main(){
    set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(1);
    s.insert(3);
    s.insert(5);
    cout<<s.size()<<endl;
    s.erase(3);
    if(s.find(3)!=s.end()){
        cout<<"exists"<<endl;
    }
    else    cout<<"No";
    for(auto &it: s){
        cout<<it<<endl;
    }
}