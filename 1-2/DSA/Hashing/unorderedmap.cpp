#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>

using namespace std;

int main(){
    map<string,int>m;
    m["China"]=150;
    m["US"]=50;
    m["Nepal"]=10;
    m["india"]=150;
    m["india"]=100;
    for(auto &it : m){
        cout<<it.first<<" "<<it.second<<endl;
    }
    m.erase("india");
    if(m.count("india")){
        cout<<"exists";
    }
    else{
        cout<<"No";
    }
}