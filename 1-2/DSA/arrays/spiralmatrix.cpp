#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int minc=0,maxc=m-1;
    int minr=0,maxr=n-1;
    while(minc<=maxc && minr<=maxr){
        for(int i=minc;i<=maxc;i++){
            cout<<arr[minr][i]<<" ";
        }
        minr++;
        for(int i=minr;i<=maxr;i++){
            cout<<arr[i][maxc]<<" ";
        }
        maxc--;
        if (minr <= maxr) {
            for(int i=maxc;i>=minc;i--){
                cout<<arr[maxr][i]<<" ";
            }
            maxr--;
        }
        if (minc <= maxc) {
            for(int i=maxr;i>=minr;i--){
                cout<<arr[i][minc]<<" ";
            }
            minc++;
        }
    }


    //DiagonalSum
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i][i];
        if(i!=(n-i-1))
            sum+=arr[i][n-1-i];
    }
    return 0;
}