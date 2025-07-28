#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    int size;
    cin>>size;
    int* arr=new int[size];
    //arr[0]=*(arr+0);
    delete[] arr;
}