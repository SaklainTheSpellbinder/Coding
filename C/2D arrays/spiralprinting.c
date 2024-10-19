#include<stdio.h>
int main()
{
    int arr[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int n=3;
    int m=3;
    int minr=0;
    int maxr=n-1;
    int minc=0;
    int maxc=m-1;
    while( maxr>=minr)
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
        if(minr<=maxr)
        {
        for(int col=maxc;col>=minc;col--)
        {
            printf("%d ",arr[maxr][col]);
        }
        maxr--;
        }
        if(maxc>=minc)
        {
        for(int row=maxr;row>=minr;row--)
        {
            printf("%d ",arr[row][minc]);
        }
        minc++;
        }
    }
    return 0;
}