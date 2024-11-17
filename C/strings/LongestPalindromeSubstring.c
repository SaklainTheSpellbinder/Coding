#include<stdio.h>
int is_pallindrome(char str[],int i,int j){
    int start=i;
    int end=j;
    int pallindrome=1;
    while(start<end){
        if(str[start]!=str[end]){
            pallindrome=0;
            break;
        }
        start++;
        end--;
    }
    return pallindrome;
}

int string_length(char str[]){
    int count=0;
    while(str[count]!='\0'){
        count++;
    }
    return count;
}

int main(){
    char s1[]="babdad";
    int n=string_length(s1);
    int maxlength=0;
    int temp=0;
    int fidx=-1,lidx=-1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(is_pallindrome(s1,i,j)){
                int length=j-i+1;
                temp=1;
                if(maxlength<length){
                    maxlength=length;
                    fidx=i;
                    lidx=j;
                }
            }
        }
    }
    if(temp){
        for(int i=fidx;i<=lidx;i++){
            printf("%c",s1[i]);
        }
    }
    else{
        printf("No Pallindrome");
    }
}