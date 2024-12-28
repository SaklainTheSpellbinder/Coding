#include<stdio.h>
int main(){
    int num=65;
    //tumi eto shohoje vulte paro onno kaoke joriye dhoro cholonay tmr choya mele na
    FILE* fp;
    fp=fopen("data.bin","wb+");
    fwrite(&num,sizeof(int),1,fp);
    rewind(fp);
    int buffer[2];
    fread(buffer,sizeof(int),2,fp);
    for(int i=0;i<2;i++){
        printf("%d\n",buffer[i]);
    }


    /*
    buffer array te first er tay 65 input hbe...kintu file e erpor to r kichu nai....tai garbadge value dekhabe complier
    depend kore ki ashte pare output e.....device er upor
    */ 
    fclose(fp);
}


/*
ei shohor amake deyni kichui shudu tomake chara
*/ 