#include<stdio.h>
int main(){
    int n;
    printf("Enter n for nxn matrix: ");
    scanf("%d",&n);
    int arr[n][n];
    int minr=0,minc=0,maxc=n-1,maxr=n-1,i=1,brr[n][n];
    while(maxr>=minr && maxc>=minc)
    {
        int col=minc;
        while(col<=maxc)
        {
            arr[minr][col]=i;
            col++;
            i++;
        }
        minr++;
        int row=minr;
        while(row<=maxr)
        {
            arr[row][maxc]=i;
            row++;
            i++;
        }
        maxc--;
        col=maxc;
        while(col>=minc && minr<=maxr)
        {
            arr[maxr][col]=i;
            col--;
            i++;
        }
        maxr--;
        row=maxr;
        while(row>=minr && minc<=maxc)
        {
            arr[row][minc]=i;
            row--;
            i++;
        }
        minc++;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}