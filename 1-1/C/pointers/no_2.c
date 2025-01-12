#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int* p=(int*)malloc(n*sizeof(int));
    int m;
    scanf("%d",&m);
    if(m<n){
        printf("Tingtong");
    }
    else{
        printf("Index out of bounds");
    }
    free(p);
}