#include<stdio.h>
#include<limits.h>
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
        if(n<=1){
            printf("Invalid input\n");
            continue;
        }
        int maximum=INT_MIN;
        int secMax=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>maximum){
                secMax=maximum;
                maximum=arr[i];
            }
            else if(arr[i]>secMax && maximum!=arr[i]){
                secMax=arr[i];
            }
        }
        if(secMax==INT_MIN){
            printf("Second largest element not found\n");
        }
        else{
            printf("%d\n",secMax);
        }

    }
}