#include<stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(n==1){
            printf("Invalid Input\n");
            continue;
        }
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        int count=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j])
                    count++;
            }
        }

        printf("%d\n",count);
    }
}