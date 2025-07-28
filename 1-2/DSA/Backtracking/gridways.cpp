#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int gridways(int n,int m,string ans){
    if((n==2 && m==1)){
        ans+="D";
        cout<<ans<<endl;
        return 1;
    }
    if(m==2 && n==1){
        ans+="R";
        cout<<ans<<endl;
        return 1;
    }
    if(n==1)
        return gridways(n,m-1,ans+"R");
    if(m==1)
        return gridways(n-1,m,ans+"D");
    return gridways(n-1,m,ans+"D")+gridways(n,m-1,ans+"R");
}

int mathgridways(int n,int m){
    m--;
    n--;
    long long product=1;
    for(int i=1;i<=n;i++){
        product*=(m+i);
        product/=i;
    }
    return product;
}

int main(){
    int n=5,m=4;
    string ans="";
    cout<<gridways(n,m,ans)<<endl;
    cout<<mathgridways(n,m)<<endl;
}

