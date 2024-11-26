#include<stdio.h>
int main(){
    int arr[5][6]={
        {1,2,3,4,5,6},
        {7,8,9,10,11,12},
        {13,14,15,16,17,18},
        {19,20,21,22,23,24},
        {25,26,27,28,29,30}
    };
    int minr=0,minc=0,maxc=5,maxr=4,i=1,brr[5][6];
    while(maxr>=minr && maxc>=minc)
    {
        int col=minc;
        while(col<=maxc)
        {
            printf("%d ",arr[minr][col]);
            col++;
        }
        minr++;
        int row=minr;
        while(row<=maxr)
        {
            printf("%d ",arr[row][maxc]);
            row++;
        }
        maxc--;
        col=maxc;
        while(col>=minc && minr<=maxr)
        {
            printf("%d ",arr[maxr][col]);
            col--;
        }
        maxr--;
        row=maxr;
        while(row>=minr && minc<=maxc)
        {
            printf("%d ",arr[row][minc]);
            row--;
        }
        minc++;
    }
    return 0;
}