#include<stdio.h>
int longestcommonsubstring(char str[],char ptr[],char result[]);

int string_length(char str[]){
    int count=0;
    while(str[count]!='\0'){
        count++;
    }
    return count;
}

int main(){
    char str[]="Saklainvalochele";
    char ptr[]="Saklainvalo";
    char result[100];
    int count=longestcommonsubstring(str,ptr,result);
    printf("%d and %s",count,result);
}

int longestcommonsubstring(char str[],char ptr[],char result[]){
    int lenstr=string_length(str);
    int lenptr=string_length(ptr);
    int dp[lenstr+1][lenptr+1];
    int endindex=0;
    int maxlength=0;

    for(int i=0;i<lenstr;i++){
        for(int j=0;j<lenptr;j++){
            dp[i][j]=0;
        }
    }

    for(int i=1;i<=lenstr;i++){
        for(int j=1;j<=lenptr;j++){
            if(str[i-1]==ptr[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>maxlength){
                    maxlength=dp[i][j];
                    endindex=i-1;
                }
            }
        }
    }


    for(int i=0;i<maxlength;i++){
        result[i]=str[endindex-maxlength+1+i];
    }
    result[maxlength]='\0';
    return maxlength;
}