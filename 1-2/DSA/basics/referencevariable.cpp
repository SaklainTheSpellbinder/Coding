#include<iostream>
using namespace std;
int main(){
    int a=5;
    int &b=a;//without initialization declare kora  jabe na
    //a and b refer to same location in memory...same memory r duita name...kono pointer na
    b=25;
    cout<<a<<"\n";
    cout<<b<<"\n";
}