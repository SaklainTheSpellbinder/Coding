#include<stdio.h>
#include<string.h>
 
void swap(char* harry,char* ginny){
    char luna=*harry;
    *harry=*ginny;
    *ginny=luna;
}
 
void permutation(char* cute,int left,int right){
    if(left==right)
        printf("%s\n",cute);
    else{
        for(int i=left;i<=right;i++){
            swap((cute+left),(cute+i));
            permutation(cute,left+1,right);                                  
            swap((cute+left),(cute+i));
        }
    }
}
int main(){
    char str[]="Saklain";                             //lemme die in your arms....let me lay down beside you....let me always be with you
    int n=strlen(str);
    permutation(str,0,n-1);
}