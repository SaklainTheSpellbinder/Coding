#include<iostream>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int main(){
    map<int,string> m;
    m[101]="Saklain";
    m[202]="tintin";
    m[303]="maramari";
    cout<<m.count(101)<<endl;
    for(auto &it:m){
        cout<<it.first<<"->"<<it.second<<endl;
    }
}