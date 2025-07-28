#include<iostream>

using namespace std;

int* func(){
    int* arr=new int;
    *arr=5;
    //delete arr;
    return arr;
}

int main(){
    int *x=func();
    cout<<*x<<endl;
}