#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int MinCoinChange(vector<int>coins,int V){
    int n=coins.size();
    int count=0;
    for(int i=n-1;i>=0 && V>0;i--){
        if(V>=coins[i]){
            count+=(V/coins[i]);
            V%=coins[i];
        }
    }
    return count;
}

int main(){
    vector<int>coins={1,2,5,10,20,50,100,500,2000};
    int V=1099;
    cout<<MinCoinChange(coins,V)<<endl;
}