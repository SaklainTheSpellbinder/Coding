#include<iostream>
using namespace std;

void binarystrings(string ans,int n){
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    
    binarystrings(ans+"0",n-1);
    if (ans.empty() || ans.back() != '1') {
        binarystrings(ans + "1", n - 1);
    }
}

int main(){
    string ans="";
    binarystrings(ans,5);
}