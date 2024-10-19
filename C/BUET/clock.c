#include<stdio.h>
#include<windows.h>
int main(){
    for(int i=0;i<60;i++)
    {
        for(int j=0;j<60;j++)
        {
            printf("%02d:%02d",i,j);
            Sleep(100);
            printf("\b\b\b\b\b");
        }
    }
    return 0;
}