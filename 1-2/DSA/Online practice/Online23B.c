#include<stdio.h>
int main(){
    char str[1000];
    scanf("%s",str);
    int len=0;
    while(str[len]!='\0') len++;
    if(len%2!=0){
        printf("NO\n");
    }
    else{
        char freq[26]={0};
        char first[1000];
        char second[1000];
        int j=0,k=0;
        for(int i=0;i<len;i++){
            int ch=str[i]-'a';
            if(freq[ch]==0){
                freq[ch]++;
                first[j++]=str[i];
            }
            else{
                freq[ch]--;
                second[k++]=str[i];
            }
        }
        first[j]='\0';
        second[k]='\0';
        int flag=0;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                flag=1;
                break;
            }
        }

        if(flag){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            printf("%s %s\n",first,second);
        }
    }
}