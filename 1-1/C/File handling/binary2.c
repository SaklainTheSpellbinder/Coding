#include<stdio.h>
struct binary{
    int a,b,c;
};
int main(){
    FILE* fp;
    struct binary tuba[4];
    tuba[0].a=1,tuba[0].b=5,tuba[0].c=6;
    tuba[1].a=2,tuba[1].b=10,tuba[1].c=11;
    tuba[2].a=3,tuba[2].b=15,tuba[2].c=16;
    tuba[3].a=4,tuba[3].b=20,tuba[3].c=65;
    fp=fopen("num.bin","wb");
    for(int i=0;i<4;i++)
    {
        fwrite(&tuba[i],sizeof(int),3,fp);   //fwrite(tuba+i,sizeof(int),3,fp);  or   //fwrite(&tuba[i],sizeof(struct binary),1,fp);
    }
    /*
    Or....
    fwrite(tuba,sizeof(struct binary),4,fp);      &tuba[i]=&*(tuba+i);     & and * cancel out.....    &tuba[i]=tuba+i;
    */

    // {
    //     fwrite(tuba,sizeof(int),12,fp);    //fwrite(&tuba[i],sizeof(struct binary),1,fp);
    // }
    fclose(fp);
    fp=fopen("num.bin","rb");
    struct binary abbi[4];
    fread(abbi,sizeof(struct binary),4,fp);
    for(int i=0;i<4;i++){
        //fread(&tuba[i],sizeof(int),3,fp);
        printf("a=%d b=%d c=%d\n",abbi[i].a, abbi[i].b,abbi[i].c);
    }
    fclose(fp);
}
//fseek(fp,0,SEEK_END);
/*
fseek(fp,0,SEEK_CUR);
fseek(fp,0,SEEK_SET);
*/ 