#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reverseWords(char *a,char *t);
int main(){
    char *str=(char *)malloc(1000*sizeof(char));
    char *result=(char *)malloc(1000*sizeof(char));
    scanf("%[^\n]s",str);
    reverseWords(str,result);
    printf("%s\n",result);
    free(str);
    free(result);
    return 0;
}

void reverseWords(char *a,char *t){
    int len=strlen(a);
    int k=0,end=len-1;
    while(end>=0 && *(a+end)==' ')
        end--;
    while(end>=0){
        int start=end;
        while(start>=0 && *(a+start)!=' ')
            start--;
        for(int i=start+1;i<=end;i++){
            *(t+k)=*(a+i);
            k++;
        }
        if(start>0){
            *(t+k)=' ';
            k++;
        }
        end=start-1;
        while(end>=0 && *(a+end)==' ')
            end--;
    }
    *(t+k)='\0';
    return;
}