#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
      void pushZerosToEnd(vector<int>& arr) {
          // code here
        int n=arr.size();
        for(int i=1;i<n;i++){
          int j=i-1;
          while(j>=0 && arr[j]==0){
            arr[j+1]=arr[j];
            j--;
          }
          arr[j+1]=arr[i];
        }
        for(int i=0;i<n;i++){
          cout<<arr[i]<<" ";
        }
        cout<<endl;
      }
  };

int main(){
  vector<int>arr={1, 2, 0, 4, 3, 0, 5, 0};
  Solution s1;
  s1.pushZerosToEnd(arr);
}