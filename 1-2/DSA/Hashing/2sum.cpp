#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {//optiaml
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int>m;
            vector<int>ans(2);
            for(int i=0;i<nums.size();i++){
                int comp=target-nums[i];
                if(m.count(comp)){
                    ans[0]=i;
                    ans[1]=m[comp];
                    return ans;
                }
                else{
                    m[nums[i]]=i;
                }
            }
            return ans;
        }
};

//optimal er cheye kharap...but emne bruteforce er cheye better

void twoSum(vector<int>&arr,int target){
    sort(arr.begin(),arr.end());
    int st=0;
    int ed=arr.size()-1;
    while(st<ed){
        int currSum=arr[st]+arr[ed];
        if(currSum==target){
            cout<<arr[st]<<","<<arr[ed]<<", idx: "<<st<<","<<ed<<endl;
            return;
        }
        else if(currSum<target){
            st++;
        }
        else
            ed--;
    }
}

void twosum(vector<int>arr,int target){//optimal
    unordered_map<int,int>m;
    for(int i=0;i<arr.size();i++){
        int comp=target-arr[i];
        if(m.count(comp)){
            cout<<arr[i]<<","<<comp<<", idx: "<<m[comp]<<","<<i<<endl;
            return;
        }
        else{
            m[arr[i]]=i;
        }
    }
    cout<<"Not found"<<endl;
}

int main(){
    vector<int>arr={1,2,7,11,15,5,9};
    twosum(arr,9);
    twoSum(arr,9);
}