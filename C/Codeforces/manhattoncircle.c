#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        getchar();
        char arr[n][m];
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
                scanf("%c",&arr[j][k]);
            getchar();
        }
        int rj,rk;
        int maxrow=0;
        int maxcol=0;
        for(int j=0;j<n;j++)
        {
            int col=0;
            for(int k=0;k<m;k++)
            {
                if(arr[j][k]=='#')
                {
                    col++;
                }
            }
            if(col>maxcol)
            {   
                maxcol=col;
                rj=j+1;
            }
        }
        for(int k=0;k<m;k++)
        {
            int row=0;
            for(int j=0;j<n;j++)
            {
                if(arr[j][k]=='#')
                {
                    row++;
                }
            }
            if(row>maxrow)
            {   
                maxrow=row;
                rk=k+1;
            }
        }
        int g=rj;
        int f=rk;
        printf("%d %d\n",g,f);
    }
}