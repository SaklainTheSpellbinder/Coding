#include<stdio.h>
#include<stdlib.h>
void allocate(int**** p,int n,int m,int l){
    *p=(int***)malloc(n*sizeof(int**));
    for(int i=0;i<n;i++){
        *(*p+i)=(int**)malloc(m*sizeof(int*));
        for(int j=0;j<m;j++){
            *(*(*p+i)+j)=(int*)malloc(l*sizeof(int));
        }
    }
}

void deallocate(int**** p,int n,int m,int l){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            free(*(*(*p+i)+j));
        }
        free(*(*p+i));
    }
    free(*p);
    *p=NULL;
}

int main(){
    int n,m,l;
    scanf("%d%d%d",&n,&m,&l);
    int ***p;
    allocate(&p,n,m,l);
    deallocate(&p,n,m,l);
}