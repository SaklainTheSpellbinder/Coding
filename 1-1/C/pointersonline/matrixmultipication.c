#include<stdio.h>
#include<stdlib.h>
int main(){
    int** p;
    p=(int**)malloc(3*sizeof(int*));
    for(int i=0;i<3;i++){
        *(p+i)=(int*)malloc(4*sizeof(int));
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", *(p + i) + j);  // Access each element correctly
        }
    }
   int** q;
    q = (int**)malloc(4 * sizeof(int*));
    for (int i = 0; i < 4; i++) {
        *(q + i) = (int*)malloc(3 * sizeof(int));
    }

    // Reading matrix q (4x3)
    printf("Enter elements for matrix q (4x3):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", *(q + i) + j);  // Access each element correctly
        }
    }


    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //        *(*(q+j)+i)= *(*(p+i)+j);
    //     }
    // }
    

    // for(int i=0;i<4;i++){
    //     int first=0,last=2;
    //     while(first<=last){
    //         int temp=*(*(q+i)+first);
    //         *(*(q+i)+first)=*(*(q+i)+last);
    //         *(*(q+i)+last)=temp;
    //         first++;
    //         last--;
    //     }
    // }


    int** r;
    r=(int**)malloc(3*sizeof(int*));
    for(int i=0;i<3;i++){
        *(r+i)=(int*)malloc(3*sizeof(int));
    }

     for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            r[i][j] = 0;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<4;k++){
                *(*(r+i)+j)+=(*(*(p+i)+k))*(*(*(q+k)+j));
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", *(*(r + i) + j));  // Access each element correctly
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++) {
        free(*(p + i));  // Free each row
    }
    free(p);
    for (int i = 0; i < 4; i++) {
        free(*(q + i));  // Free each row
    }
    free(q);
    for (int i = 0; i < 3; i++) {
        free(*(r + i));  // Free each row
    }
    free(r);
}