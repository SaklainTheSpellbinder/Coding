#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

class Result{
public:
    int sum;
    int start;
    int end;
};

Result crossing(vector<int>&arr,int si,int mid,int ei){
    int maxleft=mid;
    int sum=0,leftmax=INT_MIN;
    for(int i=mid;i>=si;i--){
        sum+=arr[i];
        if(sum>leftmax){
            leftmax=sum;
            maxleft=i;
        }
    }
    sum=0;
    int maxRight=mid+1;
    int rightsum=INT_MIN;
    for(int i=mid+1;i<=ei;i++){
        sum+=arr[i];
        if(sum>rightsum){
            rightsum=sum;
            maxRight=i;
        }
    }

    return {leftmax+rightsum,maxleft,maxRight};
}


Result maximumsubarray(vector<int>&arr, int si,int ei){
    if(si==ei){
        return {arr[si],si,si};
    }
    int mid=si+(ei-si)/2;
    Result left=maximumsubarray(arr,si,mid);
    Result right=maximumsubarray(arr,mid+1,ei);
    Result cross=crossing(arr,si,mid,ei);

    if(left.sum>right.sum && left.sum>cross.sum){
        return left;
    }
    else if(right.sum>left.sum && right.sum>cross.sum){
        return right;
    }
    else{
        return cross;
    }
}

int main() {
    FAST_IO;
    vector<int>arr={-3,4,-1,2,1,-5,4};
    Result ans=maximumsubarray(arr,0,arr.size()-1);
    cout<<ans.sum<<endl;
    for(int i=ans.start;i<=ans.end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}