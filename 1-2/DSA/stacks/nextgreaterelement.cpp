#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void nextgreaterelement(vector<int>&arr,vector<int>&ans){
    int n=arr.size();
    stack<int>s;
    ans[n-1]=-1;
    s.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && arr[i]>=s.top()){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        s.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>arr={6,8,0,1,3};
    vector<int>ans(6,0);
    nextgreaterelement(arr,ans);
}