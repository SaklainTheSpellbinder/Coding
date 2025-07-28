#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int n=numbers.size();
            int st=0;
            int ed=n-1;
            vector<int>ans(2);
            while(st<ed){
                int currSum=numbers[st]+numbers[ed];
                if(currSum==target){
                    ans[0]=st;
                    ans[1]=ed;
                    return ans;
                }
                else if(currSum>target){
                    ed--;
                }
                else
                    st++;
            }
            return ans;
        }
};

int main(){
    
}