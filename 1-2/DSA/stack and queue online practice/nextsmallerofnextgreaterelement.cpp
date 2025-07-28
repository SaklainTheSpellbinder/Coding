#include<iostream>
#include "stack.h"
using namespace std;

int main(){
    ListStack* ls=new ListStack();
    int arr[]={5, 1, 9, 2, 5, 1, 7};
    int n=sizeof(arr)/sizeof(arr[0]);
    ls->push(-1);
    int nsl[n];
    int ngl[n];
    for(int i=n-1;i>=0;i--){
        while(ls->size()>1 && arr[ls->top()]>=arr[i]){
            ls->pop();
        }
        nsl[i]=ls->top();
        ls->push(i);
    }
    ls->clear();
    ls->push(-1);
    for(int i=n-1;i>=0;i--){
        while(ls->size()>1 && arr[ls->top()]<=arr[i]){
            ls->pop();
        }
        ngl[i]=ls->top();
        ls->push(i);
    }
    int result[n];
    for(int i=0;i<n;i++){
        if(ngl[i]==-1 || nsl[ngl[i]]==-1){
            result[i]=-1;
        }
        else{
            result[i]=arr[nsl[ngl[i]]];
        }
    }
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}