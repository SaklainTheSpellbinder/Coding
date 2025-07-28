#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int totalthistypeofsubstring(string s, int si, int ei,long long& count){
    if(si>ei){
        return 0;
    }
    if(si==ei){
        if(s[si]=='1'){
            count++;
            return 1;
        }
        else{
            return 0;
        }
    }
    int mid=si+(ei-si)/2;
    int left=totalthistypeofsubstring(s,si,mid,count);
    int right=totalthistypeofsubstring(s,mid+1,ei,count);
    int n=ei-si+1;
    if(left+right>(n/2)){
        count++;
    }
    return left+right;
}

long long countSubstring(string S) {
    // code here
    long long count=0;
    totalthistypeofsubstring(S,0,S.size()-1,count);
    return count;
}

int main() {
    FAST_IO;
    cout<<countSubstring("011");
    return 0;
}