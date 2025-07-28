#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int adjacent(string &nums,int si,int ei){
    if(si>=ei){
        return 0;
    }
    int mid=si+(ei-si)/2;
    int left=adjacent(nums,si,mid);
    int right=adjacent(nums,mid+1,ei);
    if(nums[mid]>nums[mid+1]){
        return left+right+1;
    }
    return left+right;
}

int main() {
    FAST_IO;
    int inv_count=0;
    string thing="abdcbabxawer";
    inv_count=adjacent(thing,0,thing.size()-1);
    cout<<inv_count<<endl;
    return 0;
}