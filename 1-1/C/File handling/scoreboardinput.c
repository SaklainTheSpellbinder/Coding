#include<stdio.h>
int main(){
    char str[100];
    int n=3;
    int score;
    FILE *fp;
    fp=fopen("score.txt","w+");
    for(int i=1;i<=n;i++){
        printf("Enter Name:");
        scanf("%s",str);
        printf("Enter score:");
        scanf("%d",&score);  
        fprintf(fp,"%d. %s : %d\n",i,str,score);
    }
    rewind(fp);
    while(fscanf(fp,"%*d%*[.] %[^:] : %d\n",str,&score)!=EOF){
        printf("Name: %s and Score: %d\n",str,score);
    }
    fclose(fp);
}


/*
scanf("%*s %d",&a);
ekhane compiler input newar shomoy first e  string input dileo count krbe na....jtkkhn na prjnto ekta 
whitespace ashe....eta ashlei er por theke input nea start krbe
I mean jodi ami input diy "Saklain 100" tahole shudu 100 kei input nibe integer hishebe.....moja  na??

scanf fscanf sscanf shb gular jonnoi khate eta

*/ 
