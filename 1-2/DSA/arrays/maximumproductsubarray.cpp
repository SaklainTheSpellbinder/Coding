#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maxProduct(vector<int> &nums){
    int maxproduct=nums[0];
    int minproduct=nums[0];
    int ans=maxproduct;
    for(auto it=nums.begin()+1;it<nums.end();it++){
        if((*it)<0)
            swap(minproduct,maxproduct);
        maxproduct=max((*it),(*it)*maxproduct);
        minproduct=min((*it),(*it)*minproduct);
        ans=max(ans,maxproduct);
    }
    return ans;
}

int main(){
    vector<int>nums={-2,0,-1};
    cout<<maxProduct(nums)<<"\n";
}