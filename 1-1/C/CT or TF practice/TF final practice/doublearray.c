#include<stdio.h>
int main(){
    int m[4][3]={
        {1,2,3},
        {3,4,5},
        {4,7,8},
        {8,9,10}
    };
    int *p=&m[0][0];
    printf("%d",m[2][2]);
    printf("\n%d",*(p+2*3+2));
    return 0;
}