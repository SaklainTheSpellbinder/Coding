#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        int sum=0;;
        int flag=0;
        while(flag==0)
        {
            int k=0;
            flag=1;
            for(int i=1;i<n;i++)
            {
                if(arr[i-1]>arr[i])
                {
                    arr[i]++;
                    k++;
                    flag=0;
                }

            }
            if(k==0)
                break;
            sum=sum+k+1;
        }
        printf("%d\n",sum);
    }
    return 0;
}