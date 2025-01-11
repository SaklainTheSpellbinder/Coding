#include<stdio.h>
#include<string.h>
int main(){
    FILE *fp;
    fp=fopen("saklain.txt","w+");
    if(fp==NULL){
        printf("Not found");
    }
    //fseek(fp,0,SEEK_END);
    char str[200];
    char ptr[200];
    char str3[200];
    char hey[1000];
    fprintf(fp,"%s %d\n%s %s %s","Saklain er cheye valo manush hoy na",2305004,"kire","abbi","gadha");// erkm kintu fscanf sscanf egulote kora jabe na
    rewind(fp); // abar file er shurute pathai dey pointer ke fole notun kore abar open kora lage na.....ek open ei kaj kora jay....jeta onk valo jinish......tai naki?? valo kemne??
    /*Hello ami saklain amr theke valo keo nei....ami 
    shb cheye valo manush er theke valo hote parle tmra amake bolio kintu parba na tmra....ami to pari na
    eto noob ami
    */ 
    //fp=fopen("saklain.txt","r");
    fgets(hey,999,fp);
    printf("%s\n",hey);
    fscanf(fp,"%s %s %s",str,ptr,str3);
    printf("%s\n%s\n%s\n%s",hey,str,ptr,str3);
    fprintf(fp,"\n");
    fputs(hey,fp);
    fclose(fp);
}
// last e jete hole fseek(fp,0,SEEK_END);