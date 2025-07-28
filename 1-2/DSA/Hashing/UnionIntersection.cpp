#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<string>

using namespace std;

void printiternary(unordered_map<string,string>&tickets){
    unordered_set<string>to;
    for(auto &it: tickets){
        to.insert(it.second);
    }

    string start="";
    for(auto &it:tickets){
        if(!to.count(it.first)){
            start=it.first;
        }
    }

    cout<<start;
    while(tickets.count(start)){
        cout<<"->"<<tickets[start];
        start=tickets[start];
    }
    cout<<"\n";
}

int main(){
    unordered_map<string,string>tickets;
    tickets["Chennai"]="Bengaluru";
    tickets["Mumbai"]="Delhi";
    tickets["Goa"]="Chennai";
    tickets["Delhi"]="Goa";
    printiternary(tickets);
}