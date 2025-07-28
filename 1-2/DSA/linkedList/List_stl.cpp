#include<iostream>
#include<list>
#include<iterator>
using namespace std;

int main(){
    list<int>ll;

    /*
    functions in stl list
    push_front(val)
    push_back(val)
    size()
    front().....eta linked list er head er val return kore
    back()....rta linked list er tail er value print kore
    pop_front()
    pop_back()
    */

    ll.push_back(1);
    ll.push_front(2);
    ll.push_back(3);
    for(auto &val: ll){
        cout<<val<<"->";
    }
    cout<<"NULL\n";
    list<int>::iterator it;
    for(it=ll.begin();it!=ll.end();++it){
        cout<<(*it)<<"->";
    }
    cout<<"NULL\n";
    cout<<ll.size()<<endl;
    cout<<ll.front()<<endl;
    return 0;

}