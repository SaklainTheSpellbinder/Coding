#include<stdio.h>
#include<string.h>
struct student{
    char name[100];
    int x;
    float f;
}arr[100];
int main(){
    strcpy(arr[0].name,"saklain");
    printf("%s",arr[0].name);
}