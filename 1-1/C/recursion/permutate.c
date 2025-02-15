#include<stdio.h>
#include<string.h>

void swap(char* harry,char* ginny){
    char luna=*harry;
    *harry=*ginny;
    *ginny=luna;
}

void permutation(char* seggs,int left,int right){
    if(left==right)
        printf("%s\n",seggs);
    else{
        for(int i=left;i<=right;i++){
            swap((seggs+left),(seggs+i));
            permutation(seggs,left+1,right);                                   
            swap((seggs+left),(seggs+i));
        }
    }
}
int main(){
    char str[]="Saklain";                             //lemme die in your arms....let me lay down beside you....let me always be with you
    int n=strlen(str);
    permutation(str,0,n-1);
}