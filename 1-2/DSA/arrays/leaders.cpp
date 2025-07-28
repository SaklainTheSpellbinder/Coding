#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

vector<int> leaders(vector<int>& arr) {
    // Code here
    vector<int>hehe;
    int curmax=INT_MIN;
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]>=curmax){
            hehe.push_back(arr[i]);
            curmax=arr[i];
        }
    }
    int first=0;
    int last=hehe.size()-1;
    while(first<=last){
        swap(hehe[first],hehe[last]);
        first++;
        last--;
    }
    return hehe;
}

int main() {
    FAST_IO;
    vector<int>arr={10,4,2,4,1};
    vector<int>hehe=leaders(arr);
    for(int i=0;i<hehe.size();i++){
        cout<<hehe[i]<<" ";
    }
    cout<<endl;
    return 0;
}