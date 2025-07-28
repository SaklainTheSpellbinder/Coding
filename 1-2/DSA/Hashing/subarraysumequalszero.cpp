#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;

int maxsubarraysumqualszero(vector<int>&arr){
    unordered_map<int,int>summap;
    summap[0]=-1;//nahole array r first er theke subarray shuru hole baad theke jabe
    int sum=0;
    int maxlength=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(summap.count(sum)){
            int curlength=i-summap[sum];
            maxlength=max(maxlength,curlength);
        }
        else{
            summap[sum]=i;
        }
    }
    return maxlength;
}

int main(){
    vector<int>arr={3,-3,2,-2};
    cout<<maxsubarraysumqualszero(arr)<<endl;
}