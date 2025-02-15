#include<stdio.h>
int main(int argc,char* argv[]){
    FILE* fp=fopen(argv[1],"r");
    int sum=0;
    int num;
    while(fscanf(fp,"%d\n",&num)!=EOF){
        if(num%2!=0){
            sum+=num;
        }
    }
    fclose(fp);
    printf("The sum is %d",sum);
    return 0;
}