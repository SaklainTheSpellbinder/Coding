#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int brr[100000]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        brr[arr[i]]++;
    }
    int max=brr[0];
    int midx=0;
    for(int i=1;i<100000;i++){
        if(brr[i]!=0){
            printf("%d : %d times\n",i,brr[i]);
        }
        if(max<brr[i]){
            max=brr[i];
            midx=i;
        }
    }
    printf("%d",midx);
    return 0;
}