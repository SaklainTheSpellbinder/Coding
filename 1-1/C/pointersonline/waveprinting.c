#include<stdio.h>
#include<stdlib.h>
int main(){
    int**p;
    p=(int **)malloc(4*sizeof(int*));
    for(int i=0;i<4;i++){
        *(p+i)=(int *)malloc(3*sizeof(int));
    }
    for (int i = 0; i <4; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", *(p + i) + j);  // Access each element correctly
        }
    }
    // int count=12;
    int count=0;
    int i=0;
    while(count<=12){
        if(i%2==0){
            for(int j=0;j<3;j++){
                printf("%d ",*(*(p+i)+j));
            }
            i++;
        }
        else{
            for(int j=2;j>=0;j--){
                printf("%d ",*(*(p+i)+j));
            }
            i++;
        }
    }
    for (int i = 0; i < 4; i++) {
        free(*(p + i));  // Free each row
    }
    free(p);
    return 0;
}