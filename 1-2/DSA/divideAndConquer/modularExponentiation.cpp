#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int powMod(int x,int n,int M){
    int res=1;
    while(n>=1){
        if(n&1){
            res=(res*x)%M;
            n--;
        }
        else{
            x=(x*x)%M;
            n/=2;
        }
    }
    return res;
}

int sqrtfloor(int n){
    int low=1,high=n;
    int res=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid*mid<=n){
            res=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return res;
}

int main() {
    FAST_IO;
    cout<<sqrtfloor(11)<<endl;
    return 0;
}