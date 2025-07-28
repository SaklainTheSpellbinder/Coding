#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

int main(){
    vector<int>arr={4,3,2,5,6,7,3,4,2,1};
    unordered_set<int>s;
    for(int i=0;i<arr.size();i++){
        s.insert(arr[i]);
    }
    for(auto &it:s){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<s.size()<<endl;
}