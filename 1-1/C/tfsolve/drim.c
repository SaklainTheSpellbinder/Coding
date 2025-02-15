#include <stdio.h>

int main() {
    int M = 4; // Assuming a 3x3 matrix as in the given problem
    int A[4][4] = {
        {1, 1, 1,1},
        {3, 3, 4,5},
        {5, 6, 7,5},
        {1 ,3, 5,6}
    };

    int count = 0;
    // Checking the primary diagonal
    for (int i = 0; i < M; i++) {
        int num = A[i][i];
        int found=0;
        for(int j=0;j<M;j++){
            for(int k=0;k<M;k++){
                if(!((i==k)&&(i==j))&& num==A[j][k]){
                    found=1;
                    break;
                }
            }
        }
        if(found==0)
        count++;
    }
    // Checking the secondary diagonal
    for (int i = 0; i < M; i++) {
        int num = A[i][M - 1 - i];
        int found=0;
        if(i==(M-1-i)) continue;
        for(int j=0;j<M;j++){
            for(int k=0;k<M;k++){
                if(!(((M-1-i)==k)&&(i==j))&& num==A[j][k]){
                    found=1;
                    break;
                }
            }
        }
        if(!found)
            count++;
    }
    
    
    printf("%d\n", count);

    return 0;
}
