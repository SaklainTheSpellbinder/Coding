#include<iostream>
#include<algorithm>
using namespace std;
void staircasesearch(int* arr[],int n,int m,int key){
    int i=0,j=m-1;
    while(i<n && j>=0){
        if(arr[i][j]==key){
            cout<<"Found at "<<i<<","<<j<<"\n";
            return;
        }
        else if(arr[i][j]<key)
            i++;
        else
            j--;
    }
    cout<<"not found"<<"\n";
    return;
}