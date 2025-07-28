#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

void nextPermutation(vector<int>& arr) {
    // code here
    int n=arr.size();
    int i=n-2;
    int j=n-1;
    
    while(i>=0 && arr[i]>=arr[i+1]){
        i--;
    }
    
    if(i>=0){
        while(j>i && arr[j]<=arr[i]){
            j--;
        }
        swap(arr[i],arr[j]);
    }
    
    reverse(arr.begin()+i+1,arr.end());
}

int main() {
    FAST_IO;
    
    return 0;
}