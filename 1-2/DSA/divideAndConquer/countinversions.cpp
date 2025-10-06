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
        if(nums[i]<=nums[j]){
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

void sami_r_significant_inversion(vector<int>& nums,int si,int mid,int ei,int& inv_count){
    vector<int>temp(ei-si+1);
    int k=0;
    int i=si;
    int j=mid+1;
    while(i<=mid){
        while(j<=ei && nums[i]>2*nums[j]){
            j++;
        }
        inv_count+=(j-(mid+1));
        i++;
    }

    k=0;
    i=si;
    j=mid+1;
    while(i<=mid && j<=ei){
        if(nums[i]<=nums[j]){
            temp[k++]=nums[i++];
        }
        else{
            temp[k++]=nums[j++];
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

void kothin_inversion(vector<int>&nums,int si,int ei,int& inv_count){
    if(si>=ei){
        return;
    }
    int mid=si+(ei-si)/2;
    kothin_inversion(nums,si,mid,inv_count);
    kothin_inversion(nums,mid+1,ei,inv_count);
    sami_r_significant_inversion(nums,si,mid,ei,inv_count);
}

int main(){
    vector<int>arr={2,4,1,3,5};
    int inv_count=0;
    mergesort(arr,0,arr.size()-1,inv_count);
    int sig_inv_count=0;
    vector<int>arr2={13, 8, 25, 6, 12, 4, 2, 8, -5};
    kothin_inversion(arr2,0,arr2.size()-1,sig_inv_count);
    cout<<sig_inv_count<<endl;
    cout<<inv_count<<endl;
}