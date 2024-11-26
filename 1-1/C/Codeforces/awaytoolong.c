#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++)
    {
        char str[100];
        gets(str);
        int x=strlen(str);
        if(x>10){
           printf("%c%d%c\n",str[0],x-2,str[x-1]);
        }
        else
        printf("%s\n",str);
    } 
    return 0;

    
}