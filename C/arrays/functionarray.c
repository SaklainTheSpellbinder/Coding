#include<stdio.h>
void fun(int x[]){
    x[0]=190;
    return;
}
int main(){
    int arr[5]={1,5,6,4,3};
    printf("%d\n",arr[0]);
    fun(arr);
    printf("%d",arr[0]);
    return 0;
}