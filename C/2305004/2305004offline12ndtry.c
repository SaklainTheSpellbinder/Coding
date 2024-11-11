#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int bidx[n+1];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        int r;
        scanf("%d",&r);
        bidx[r]=i;
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++){
            if(bidx[arr[i]]<bidx[arr[j]]){
                count++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}