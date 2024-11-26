#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int count=0;
    for(int i=0;i<n;i++){
        int temp=0;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                temp=1;
                break;
            }
        }
        if(temp==0){
            count++;
        }
    }
    printf("%d",count);
}