#include<stdio.h>
int replace_count(char s1[],char s2[],char s3[],char s4[]);
int main(){
    char s1[100]="I like akif";
    char s2[100]="akif";
    char s3[100]="rra";
    char s4[100];
    printf("Resulting string: %s\nNumber of replacements: %d\n",s4,replace_count(s1,s2,s3,s4));
    return 0;
}

int replace_count(char s1[],char s2[],char s3[],char s4[]){
    int count=0;
    int k=0,i=0;
    while(s1[i]!='\0'){
        int match=1;
        int temp=0;
        while(s2[temp]!='\0'){
            if(s1[temp+i]!=s2[temp]){
                match=0;
                break;
            }
            temp++;
        }
        if(match==1){
            int p=0;
            count++;
            while(s3[p]!='\0'){
                s4[k]=s3[p];
                p++;
                k++;
            }
            i+=temp;
        }
        else{
            s4[k]=s1[i];
            k++;
            i++;
        }
    }
    s4[k]='\0';
    return count;
}