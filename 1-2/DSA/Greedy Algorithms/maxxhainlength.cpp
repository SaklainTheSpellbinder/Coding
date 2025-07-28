#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comparator(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int MaxChainLength(vector<pair<int,int>>&vec){
    int n=vec.size();
    sort(vec.begin(),vec.end(),comparator);
    int count=1;
    int currEnd=vec[0].second;
    for(int i=1;i<n;i++){
        if(vec[i].first>currEnd){
            count++;
            currEnd=vec[i].second;
        }
    }
    return count;
}

int main(){
    vector<pair<int,int>>vec={{5,24},{39,60},{5,28},{27,40},{50,90}};
    cout<<"max length is: "<<MaxChainLength(vec)<<endl;
}