#include<stdio.h>
#include<string.h>
int main(){
    char ch[4];
    char bh[4];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s%s",ch,bh);
        char temp=ch[0];
        ch[0]=bh[0];
        bh[0]=temp;
        printf("%s %s\n",ch,bh);
    }
    
    return 0;
}