#include<stdio.h>
void EvenOddArray(int arr[],int n);
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    EvenOddArray(arr,n);
    return 0;
}

void EvenOddArray(int arr[],int n){
    int a[n];
    int b[n];
    int evensize=0;
    int oddsize=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            a[evensize]=arr[i];
            evensize++;
        }
        else{
            b[oddsize]=arr[i];
            oddsize++;
        }
    }
    printf("Even:{ %d",a[0]);
    for(int i=1;i<evensize;i++){
        printf(", %d",a[i]);
    }
    printf("}\n");
    printf("Odd:{ %d",b[0]);
    for(int i=1;i<oddsize;i++){
        printf(", %d",b[i]);
    }
    printf("}\n");
    return;
}