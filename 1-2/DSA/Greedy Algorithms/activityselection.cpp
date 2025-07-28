#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comparator(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int maxActivities(vector<int>start, vector<int>end){
    vector<pair<int,int>>p;
    for(int i=0;i<start.size();i++){
        p.emplace_back(start[i],end[i]);
    }
    sort(p.begin(),p.end(),comparator);
    //sort on end time....but eta kore dewa ache ques e
    cout<<"selecting A0\n";
    int count=1;
    int currEndTime=p[0].second;

    for(int i=1;i<start.size();i++){
        if(p[i].first>=currEndTime){
            cout<<"selecting A"<<i<<endl;
            count++;
            currEndTime=p[i].second;
        }
    }
    return count;
}

int main(){
    vector<int>start={1,3,0,5,8,5};
    vector<int>end={2,4,6,7,9,9};
    cout<<maxActivities(start,end)<<endl;
    //vector<pair<int,int>>act(3,make_pair(0,0))
    //vector<pair<int,int>>tingtong={{0,9},{1,2},{2,4}};
    
}


