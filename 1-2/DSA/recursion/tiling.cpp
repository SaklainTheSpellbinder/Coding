#include<iostream>
using namespace std;

int tilingways(int n){
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    return tilingways(n-1) + tilingways(n-2);
}

int main(){
    int n=4;
    cout<<tilingways(n)<<endl;
}