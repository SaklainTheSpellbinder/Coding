#include<stdio.h>
 
int main(){
    int id=-1, l1, l2, t, k ,len;
    l1 = l2 = len =k=0;
    char s1[80], s2[80];
    gets(s1);
    gets(s2);
    while(s1[l1]!='\0') l1++;
    while(s2[l2]!='\0') l2++;
 
    for(int i=0; i<l1; i++){
        for(int j=0; j<l2; j++){
            if(s1[i]==s2[j]){
                k=0;
                while(s1[i+k]==s2[j+k]){
                    if((i+k)>=l1 || (j+k)>=l2) break;
                    k++;
                }
                if(k>len){
                    len =k;
                    id = i;
                }
            }
        }
    }
    if(id==-1) printf("No common substring");
    else
         for(int i=id; i<len+id; i++) printf("%c",s1[i]);
        return 0;
}