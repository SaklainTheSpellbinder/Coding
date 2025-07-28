#include<iostream>
#include<string>

using namespace std;

int main(){
    int** arr=new int*[4];
    for(int i=0;i<4;i++){
        *(arr+i)=new int[3];
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            arr[i][j]=i+j;
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    for(int i=0;i<4;i++){
        delete[] *(arr+i);  
    }
    delete[] arr;
}  