#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

void reverse(vector<int>&arr,int first,int last){
    while(first<last){
        swap(arr[first],arr[last]);
        first++;
        last--;
    }
}

// Function to rotate an array by d elements in counter-clockwise direction.
void rotateArr(vector<int>& arr, int d) {
    // code here
    int n=arr.size();
    
    d=d%n;
    
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
    
}

int main() {
    FAST_IO;
    
    return 0;
}