#include<stdio.h>
#include<string.h>
int main(){
    char str[16]="College Wallah";
    printf("In which position do you want to insert:");
    int n;
    scanf("%d",&n);
    getchar();
    printf("Which character do you want to insert:");
    char ch;
    scanf("%c",&ch); 
    for(int i=14;i>=n;i--)
    {
        str[i+1]=str[i];
    }
    str[n]=ch;
    printf("%s\n",str);
    return 0;
}