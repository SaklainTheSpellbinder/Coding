#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        vector<int>hehe;
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0){
                hehe.push_back(arr[i]);
            }
            else{
                count++;
            }
        }
        for(int i=0;i<count;i++){
            hehe.push_back(0);
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=hehe[i];
        }
    }
  };

int main(){
  vector<int>arr={1, 2, 0, 4, 3, 0, 5, 0};
  Solution s1;
  s1.pushZerosToEnd(arr);
  for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}