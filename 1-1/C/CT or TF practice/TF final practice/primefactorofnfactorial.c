#include<stdio.h>

int main(){
    int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int b[25] = {0}; // Array to store the count of divisions for each prime
    int x, i;
    scanf("%d",&x);
    for(int i=0;i<25;i++){
        int count=0;
        for(int j=1;j<=x;j++){
            int temp=j;
            while(temp%a[i]==0){
                count++;
                temp/=a[i];
            }
        }
        b[i]=count;
    }
    for(int i=0;i<25;i++){
        if(b[i]>0){
            int j=0;
            while(j<=b[i]){
                printf("%d*",a[i]);
                j++;
            }
        }
    }
}