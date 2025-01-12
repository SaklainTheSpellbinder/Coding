#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,m,l;
    scanf("%d%d%d",&n,&m,&l);
    int*** p=(int***)malloc(n*sizeof(int**));
    for(int i=0;i<n;i++){
        *(p+i)=(int**)malloc(m*sizeof(int*));
        for(int j=0;j<m;j++){
        *(*(p+i)+j)=(int*)malloc(l*sizeof(int));
    }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<l;k++){
                scanf("%d",(*(*(p+i)+j)+k));
            }
        }
    }
    printf("\n");

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<l;k++){
                printf("%d ",*(*(*(p+i)+j)+k));
            }
            printf("\n");
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            free(*(*(p+i)+j));
        }
        free(*(p+i));
    }
    free(p);
}