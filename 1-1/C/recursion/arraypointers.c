#include<stdio.h>
int fun(int (*fuc)[5]){
    return sizeof(*fuc);
}
int main(){
    int arr[5];
    printf("%d",fun(&arr));
}