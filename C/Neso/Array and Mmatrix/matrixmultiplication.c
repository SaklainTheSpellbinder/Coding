#include<stdio.h>
int main(){
    int n,m,p,q;

    printf("Enter the rows and columns of matrix A: ");
    scanf("%d%d",&n,&m);
    getchar();
    printf("Enter the elements of matrix A:\n");
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("Enter the rows and columns of matrix B: ");
    scanf("%d%d",&p,&q);
    getchar();
    printf("Enter the elements of matrix B:\n");
    int brr[p][q];
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            scanf("%d",&brr[i][j]);
        }
    }
    int mulans[n][q];
    if(m!=p)
        printf("Multiplication is not possible");
    else{
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<q;j++)
            {
                int sum=0;
                for(int k=0;k<m;k++)
                {
                    sum+=arr[i][k]*brr[k][j];
                }
                mulans[i][j]=sum;
            }
        }
    }

    printf("Resultant matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<q;j++)
        {
            printf("%d ",mulans[i][j]);
        }
        printf("\n");
    }

    return 0;
}