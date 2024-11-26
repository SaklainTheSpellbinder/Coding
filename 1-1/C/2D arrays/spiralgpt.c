#include<stdio.h>
int main()
{
    int arr[4][6]={
        {1,2,3,4,5,6},
        {7,8,9,10,11,12},
        {13,14,15,16,17,18},
        {19,20,21,22,23,24}
    };
    int n=4;
    int m=6;
    int minr=0;
    int maxr=n-1;
    int minc=0;
    int maxc=m-1;
    while(minr<=maxr && minc<=maxc)
    {
        for(int col=minc;col<=maxc;col++)
        {
            printf("%d ",arr[minr][col]);
        }
        minr++;
        for(int row=minr;row<=maxr;row++)
        {
            printf("%d ",arr[row][maxc]);
        }
        maxc--;
        
        // Print the bottom row in reverse direction
        if (minr <= maxr) {
            for(int col=maxc;col>=minc;col--)
            {
                printf("%d ",arr[maxr][col]);
            }
            maxr--;
        }
        
        // Print the leftmost column in reverse direction
        if (minc <= maxc) {
            for(int row=maxr;row>=minr;row--)
            {
                printf("%d ",arr[row][minc]);
            }
            minc++;
        }
    }
    return 0;
}
