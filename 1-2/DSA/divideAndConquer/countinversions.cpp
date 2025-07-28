#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void merge(vector<int>& nums,int si,int mid,int ei,int& inv_count){
    vector<int>temp(ei-si+1);
    int k=0;
    int i=si;
    int j=mid+1;
    while(i<=mid && j<=ei){
        if(nums[i]<nums[j]){
            temp[k++]=nums[i++];
        }
        else{
            temp[k++]=nums[j++];
            inv_count+=(mid-i+1);
        }
    }
    while(i<=mid){
        temp[k++]=nums[i++];
    }
    while(j<=ei){
        temp[k++]=nums[j++];
    }

    for(int m=0;m<temp.size();m++){
        nums[si+m]=temp[m];
    }
}

void mergesort(vector<int>&nums,int si,int ei,int& inv_count){
    if(si>=ei){
        return;
    }
    int mid=si+(ei-si)/2;
    mergesort(nums,si,mid,inv_count);
    mergesort(nums,mid+1,ei,inv_count);
    merge(nums,si,mid,ei,inv_count);
}

int main(){
    vector<int>arr={2,4,1,3,5};
    int inv_count=0;
    mergesort(arr,0,arr.size()-1,inv_count);
    cout<<inv_count<<endl;
}