#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<int,int>m;
    vector<int>arr={1,3,2,5,1,3,1,5,1};
    int freq=arr.size()/3;
    for(int i=0;i<arr.size();i++){
        if(m.count(arr[i]))
            m[arr[i]]++;
        else
            m[arr[i]]=1;
    }

    for(auto &it:m){
        if(it.second>freq)
            cout<<it.first<<" ";
    }
    cout<<endl;
}