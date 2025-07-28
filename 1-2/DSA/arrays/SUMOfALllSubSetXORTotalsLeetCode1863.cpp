#include<iostream>
#include<vector>
using namespace std;

int subsetXORSum(vector<int>& nums) {
    if(nums.size()==0)
        return 0;
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        int k=1;
        while((i+k)<nums.size()){
            int x=nums[i];
            for(int j=i+k;j<nums.size();j++){
                x=x^nums[j];
                sum+=x;
            }
            k++;
        }
    }
    return sum;
}

int subsetXORSum2(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result * (1 << (nums.size() - 1));
}

int main(){
    vector<int>v={3,4,5,6,7,8};
    cout<<subsetXORSum2(v);
}