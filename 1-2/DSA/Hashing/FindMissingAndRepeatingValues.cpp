#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>>

using namespace std;


class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            //(n-2)+2a=what is   //n-2+a+b=should be
            unordered_set<int>s;
            int sum=0;
            int dup;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(s.count(grid[i][j])){
                        dup=grid[i][j];
                    }
                    s.insert(grid[i][j]);
                    sum+=grid[i][j];
                }
            }
            int n=grid.size();
            int actualSum=((n*n)*((n*n)+1))/2;
            int b=actualSum+dup-sum;
            vector<int>ans(2);
            ans[0]=dup;
            ans[1]=b;
            return ans;
        }
};

int main(){
    
}