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
    int top=0,bottom=3;
    int left=0,right=2;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            printf("%d ",*(*(p+top)+i));
        }
        top++;
        for(int i=top;i<=bottom;i++){
            printf("%d ",*(*(p+i)+right));
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                printf("%d ",*(*(p+bottom)+i));
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                printf("%d ",*(*(p+i)+left));
            }
            left++;
        }
    }
    for (int i = 0; i < 4; i++) {
        free(*(p + i));  // Free each row
    }
    free(p);
    return 0;
}