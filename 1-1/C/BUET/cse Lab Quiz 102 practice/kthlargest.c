#include<stdio.h>
int main(){
    int arr[10]={1,3,4,5,3,2,2,344,8,7};
    int n=10;
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        int temp=arr[minindex];
        arr[minindex]=arr[i];
        arr[i]=temp;
    }
    int k;
    scanf("%d",&k);
    int count=1;
    int now=arr[0];
    for(int i=0;i<n;i++){
        //printf("%d ",arr[i]);
        if(arr[i]!=now){
            count++;
            now=arr[i];
        }
        if(count==k)
            break;
    }
    printf("\n%d",now);
}