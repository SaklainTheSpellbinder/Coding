#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    FAST_IO;
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int div[5]={1,0,0,0,0};
        if(n>=3 || d%3==0){
            div[1]=1;
        }
        if(d==5)
            div[2]=1;
        if(n>=6 || d==9 || (n>=3 && d==3)){
            div[4]=1;
        }
        if(n>=3 || d==7)
            div[3]=1;
        for(int i=0;i<5;i++){
            if(div[i]){
                cout<<(2*i+1)<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}