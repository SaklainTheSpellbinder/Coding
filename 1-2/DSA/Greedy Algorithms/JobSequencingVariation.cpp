#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comparator(pair<int,int>a,pair<int,int>b){
    return a.second>b.second;
}
int MaxProfit(vector<pair<int,int>>jobs){
    sort(jobs.begin(),jobs.end(),comparator);
    int profit=jobs[0].second;
    int SafeDeadline=2;
    int n=jobs.size();
    for(int i=1;i<n;i++){
        if(jobs[i].first>=SafeDeadline){
            profit+=jobs[i].second;
            SafeDeadline++;
        }
    }
    return profit;
}

int main(){
    vector<pair<int,int>>jobs={{4,20},{1,10},{1,40},{1,30}};
    cout<<MaxProfit(jobs)<<endl;
}