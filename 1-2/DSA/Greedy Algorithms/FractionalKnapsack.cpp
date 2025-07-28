#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comparator(pair<float,int>a,pair<float,int>b){
    return a.first>b.first;
}

float FractionalKnapsack(vector<int>value,vector<int>weight,int w){
    vector<pair<float,int>>v;
    float ans=0;
    for(int i=0;i<value.size();i++){
        v.emplace_back(((float)value[i]/weight[i]),i);
    }
    sort(v.begin(),v.end(),comparator);
    for(int i=0;i<value.size();i++){
        int idx=v[i].second;
        if(weight[idx]<=w){
            w-=weight[idx];
            ans+=value[idx];
        }
        else{
            ans+=((v[i].first)*w);
            w=0;
        }
        if(w==0){
            break;
        }
    }
    return ans;
}

int main(){
    vector<int>value={60,100,120};
    vector<int>weight={10,20,30};
    cout<<FractionalKnapsack(value,weight,50);
}