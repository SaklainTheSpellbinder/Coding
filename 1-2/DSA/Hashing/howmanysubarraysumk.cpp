#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;

int maxsubarraysumqualsk(vector<int>&arr,int k){
    unordered_map<int,int>summap;
    summap[0]=1;//nahole array r first er theke subarray shuru hole baad theke jabe
    int sum=0;
    int ans=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(summap.count(sum-k)){
            ans+=summap[sum-k];
        }
        if(!summap.count(sum)){
            summap[sum]=1;
        }
        else{
            summap[sum]++;
        } 
    }
    return ans;
}

int main(){
    vector<int>arr={1,2,3};
    cout<<maxsubarraysumqualsk(arr,2)<<endl;
}