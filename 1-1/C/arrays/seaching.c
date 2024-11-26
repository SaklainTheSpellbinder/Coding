#include<stdio.h>
#include<stdbool.h>
int main(){
    int arr[8]={1,2,3,4,5,6,7,8};
    int x;
    bool flag=false;
    printf("Enter the number:");
    scanf("%d",&x);
    for(int i=0;i<8;i++)
    {
        if(arr[i]==x){
            flag=true;
        printf("Found");
        break;}
    }
    if(flag==false)
    printf("Not found");
    return 0;
}