#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxProfit(vector<int>& prices) {
    int minprice=INT_MAX;
    int maxprofit=0;
    for(auto &value: prices){
        minprice=min(minprice,value);
        maxprofit=max(maxprofit,value-minprice);
    }
    return maxprofit;
}


int main(){
    vector<int>v={1};
    cout<<maxProfit(v)<<"\n";
}