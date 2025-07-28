#include<iostream>
#include<algorithm>
using namespace std;

int factorial(int n){
    if(n==0)
        return 1;
    return n * factorial(n-1);
}

void decreasing(int n){
    if(n==0)
        return;
    cout<<n<<endl;
    decreasing(n-1);
}

void increasing(int n){
    if(n==0)
        return;
    increasing(n-1);
    cout<<n<<endl;
}

bool isSorted(int arr[],int n,int i){
    if(i==n-1)
        return true;
    if(arr[i]>arr[i+1])
        return false;
    return isSorted(arr,n,i+1);
}

int firstoccurrance(int arr[],int n,int i,int key){
    if(i==n)
        return -1;
    if(arr[i]==key)
        return i;
    return firstoccurrance(arr,n,i+1,key);
}

int lastoccurrance(int arr[],int n,int i,int key){
    if(i==n)
        return -1;
    int idx= lastoccurrance(arr,n,i+1,key);
    if(arr[i]==key && idx==-1)
        return i;
    return idx;
}

int power(int x,int n){
    if(n==0)
        return 1;
    if(n==1)
        return x;

    if(n%2==0)
        return power(x,n/2)*power(x,n/2);
    if(n%2!=0)
        return x*power(x,n/2)*power(x,n/2);
}

int main(){
    cout<<factorial(5)<<endl;
    decreasing(5);
    increasing(5);
    int arr[]={1,3,5,1,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<firstoccurrance(arr,n,0,2)<<endl;
    cout<<lastoccurrance(arr,n,0,5)<<endl;
    cout<<isSorted(arr,n,0)<<endl;

    cout<<power(3,3);
}