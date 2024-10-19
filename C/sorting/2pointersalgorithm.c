#include<stdio.h>
int main(){
    int arr[8]={1,2,3,4,5,8,9,10};
    int target=8;
    int n=8;
    int i=0;
    int j=n-1;
    while(i<j){
       if(arr[i]+arr[j]==target)
       {
        printf("%d and %d",arr[i],arr[j]);
        break;
       }
       if(arr[i]+arr[j]>target)
       {
        j--;
       }
       if(arr[i]+arr[j]<target)
       {
        i++;
       }
    }
    return 0;
}