#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool isvalid(vector<int>&dist,int n,int c,int minallowed){
    int cows=1,lastpos=dist[0];

    for(int i=0;i<n;i++){
        if(dist[i]-lastpos>=minallowed){
            cows++;
            lastpos=dist[i];
        }
        if(cows==c){
            return true;
        }
    }

    return false;
}

int AggCows(vector<int>&cows,int n,int c){
    sort(cows.begin(),cows.end());
    int ans=-1;
    int end=cows[n-1]-cows[0];
    int st=1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isvalid(cows,n,c,mid)){
            ans=mid;
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int>cows(n);
        for(int i=0;i<n;i++){
            cin>>cows[i];
        }
        cout<<AggCows(cows,n,c)<<endl;
    }
    return 0;
}
