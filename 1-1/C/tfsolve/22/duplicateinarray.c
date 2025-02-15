#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int main(){
    int N;
    scanf("%d",&N);
    int arr[N];
    int max=INT_MIN;
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
        if(max<arr[i])
            max=arr[i];
    }
    int* brr=(int*)calloc(max+1,sizeof(int));
    for(int i=0;i<N;i++){
        brr[arr[i]]++;
    }
    printf("The duplicates are: ");
    for(int i=0;i<max+1;i++){
        if(brr[i]>1)
            printf("%d ",i);
    }
    free(brr);
}