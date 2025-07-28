#include<iostream>
using namespace std;
int friendspairing(int n){
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    return friendspairing(n-1) + (n-1) * friendspairing(n-2);
}

int main(){
    int n=5;
    cout<<friendspairing(n)<<endl;
}