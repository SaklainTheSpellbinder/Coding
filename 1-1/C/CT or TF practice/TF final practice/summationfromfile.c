#include<stdio.h>
int main(){
    int num;
    FILE* fp=fopen("hudai.txt","a+");
    while(1){
        scanf("%d",&num);
        if(num<0)   break;
        fprintf(fp,"%d\n",num);
    }
    rewind(fp);
    int sum=0;
    while(fscanf(fp,"%d",&num)!=EOF){
        sum+=num;
    }
    printf("%d",sum);
    fclose(fp);
}