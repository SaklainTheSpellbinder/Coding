#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//climbing stairs o same 

int fibodp(int n,vector<int>&fibo){ //O(n)
    if(n==0 || n==1)
        return n;
    if(fibo[n]!=-1){
        return fibo[n];
    }
    fibo[n]=fibodp(n-1,fibo)+fibodp(n-2,fibo);
    return fibo[n];
}

int fibtab(int n){
    vector<int>fib(n+1,0);
    fib[0]=0;
    fib[1]=1;
    
    for(int i=2;i<=n;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    return fib[n];
}
int main(){
    int n;
    cin>>n;
    vector<int>fibo(n+1,-1);
    cout<<fibodp(n,fibo)<<endl;
    cout<<fibtab(n)<<endl;
}