#include<stdio.h>
#include<stdlib.h>
int main(){
    int** p;
    p=(int**)malloc(3*sizeof(int*));
    for(int i=0;i<3;i++){
        *(p+i)=(int*)malloc(3*sizeof(int));
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", *(p + i) + j);  // Access each element correctly
        }
    }
    // int** q;
    // q=(int**)malloc(4*sizeof(int*));
    // for(int i=0;i<4;i++){
    //     *(q+i)=(int*)malloc(3*sizeof(int));
    // }
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //        *(*(q+j)+i)= *(*(p+i)+j);
    //     }
    // }
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            int temp=*(*(p+i)+j);
            *(*(p+i)+j)=*(*(p+j)+i);
            *(*(p+j)+i)=temp;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", *(*(p + i) + j));  // Access each element correctly
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++) {
        free(*(p + i));  // Free each row
    }
    free(p);
    // for (int i = 0; i < 4; i++) {
    //     free(*(q + i));  // Free each row
    // }
    // free(q);
}