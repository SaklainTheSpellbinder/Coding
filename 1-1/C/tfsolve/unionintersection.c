#include<stdio.h>
void Union(int A[],int B[],int C[],int m,int n){
    int k=0;
    for(int i=0;i<m;i++){
        int found=0;
        for(int j=0;j<k;j++){
            if(C[j]==A[i]){
                found=1;
                break;
            }
        }
        if(!found)
            C[k++]=A[i];
    }
    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<k;j++){
            if(C[j]==B[i]){
                found=1;
                break;
            }
        }
        if(!found)
            C[k++]=B[i];
    }
    for(int i=0;i<k;i++){
        printf("%d ",C[i]);
    }
}
void  intersect(int A[],int B[],int D[],int m,int n){
    int k=0;
    for(int i=0;i<m;i++){
        int okay=0;
        for(int j=0;j<n;j++){
            if(B[j]==A[i]){
                okay=1;
                break;
            }
        }
        if(okay){
            int found=0;
            for(int j=0;j<k;j++){
                if(D[j]==A[i]){
                    found=2;
                    break;
                }
            }
            if(!found)
            D[k++]=A[i];
        }
    }
    for(int i=0;i<k;i++){
        printf("%d ",D[i]);
    }
}
int main(){
    int A[]={7,1,5,2,3,6,1};
    int B[]={3,8,6,20,7,8};
    int size=(sizeof(A)/sizeof(A[0]))+(sizeof(B)/sizeof(B[0]));
    int C[size];
    intersect(A,B,C,(sizeof(A)/sizeof(A[0])),(sizeof(B)/sizeof(B[0])));
}