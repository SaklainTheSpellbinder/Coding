#include<stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        if(n<3){
            printf("Invalid input\n");
            continue;
        }
        int start=0;
        int end=2;
        int maxSum=arr[0]+arr[1]+arr[2];
        for(int i=1;i<n-2;i++){
            int sum=arr[i]+arr[i+1]+arr[i+2];
            if(sum>maxSum){
                maxSum=sum;
                start=i;
                end=i+2;
            }
        }

        for(int i=start;i<=end;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}