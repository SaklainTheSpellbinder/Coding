#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//Dutch national flag algo

//sort 0, 1 2
/*
3 pointers low mid high
0... 0 to l-1    1... l to m-1  (m to h   unsorted elementl) 2... h+1 to n-1

[2,0,2,1,1,0,1,2,0,0] 

mid=0;
high=n-1;
low=0;
while(mid<=high){

}
*/

void sortColors(vector<int>& nums) {//sc o(1)   //tc  O(n)
    int low=0,mid=0;
    int high=nums.size()-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}

int main(){

}