#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int trap(vector<int>& height) {  //O(n^2) approach
    int max=height[0];
    int sum=0;
    for(auto it=height.begin();it<height.end();++it){
        if((*it)>=max){
            max=(*it);
            if(it!=height.end()-1)
                max=min(max,*max_element(it+1,height.end()));
            if(max!=(*it))
                continue;
        }
        sum+=(max-(*it));
    }
    if(max>(*(height.end()-1))) sum--;
    return sum;
}

int trap2(vector<int>& height){
    int n=height.size();
    vector<int>leftmax(n,0);
    leftmax[0]=height[0];
    for(int i=1;i<n;i++){
        leftmax[i]=max(leftmax[i-1],height[i-1]);
    }
    vector<int>rightmax(n,0);
    rightmax[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        rightmax[i]=max(rightmax[i+1],height[i+1]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        int x=min(leftmax[i],rightmax[i]);
        if(x>height[i])
            sum+=(x-height[i]);
    }
    return sum;
}

int main(){
    vector<int>v={4,2,0,3,2,5};
    cout<<trap2(v)<<"\n";
}