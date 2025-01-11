#include<stdio.h>
void append_score(){
    char name[1000];
    int  score;
    scanf("%s %d",name,&score);
    FILE* fp=fopen("scoreboard.txt","a+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp,"Name: %s Score: %d\n",name,score);
    fclose(fp);
};

struct player{
    char name[1000];
    int score;
};

void sortingscore(){
    struct player hey[100];
    FILE* fp=fopen("scoreboard.txt","r+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    int i=0;
    while(fscanf(fp,"%*s %s %*s %d\n",hey[i].name,&hey[i].score)!=EOF){
        i++;
    }
    rewind(fp);
    for(int j=0;j<i;j++){
        int minidx=j;
        for(int k=j+1;k<i;k++){
            if(hey[k].score<hey[minidx].score){
                minidx=k;
            }
        }
        struct player temp;
        temp=hey[j];
        hey[j]=hey[minidx];
        hey[minidx]=temp;
    }
    for(int j=i-1;j>=0;j--){
        fprintf(fp,"Name: %s Score: %d\n",hey[j].name,hey[j].score);
    }
    fclose(fp);
    return;
}

int main(){
    append_score();
    sortingscore();
    return 0;
}