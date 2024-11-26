#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int* p=(int *)malloc(10001*sizeof(int));
    int max=0;
    for(int i=0;i<=10000;i++){
        *(p+i)=0;
    }
    for(int i=0;i<n;i++){
        int j;
        scanf("%d",&j);
        *(p+j)=*(p+j)+1;
        if(max<*(p+j)){
            max=*(p+j);
        }
    }
    for(int i=0;i<=10000;i++){
        if(*(p+i)==max){
            printf("%d ",i);
        }
    }
    free(p);
}