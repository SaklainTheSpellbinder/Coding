#include<iostream>
using namespace std;

int binsearch(int arr[],int n,int key){
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;  
        if(key<arr[mid])
            end=mid-1;
        if(key>arr[mid])
            start=mid+1;
        if(key==arr[mid])
            return mid;
    }
    return -1;
}

int main(){

}