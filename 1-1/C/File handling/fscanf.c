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
    for(int i=0;i<4;i++){
        fwrite(&tuba[i],sizeof(int),3,fp);
    }
    fclose(fp);
    fp=fopen("num.bin","rb");
    for(int i=0;i<4;i++){
        fread(&tuba[i],sizeof(int),3,fp);
        printf("a=%d b=%d c=%d\n",tuba[i].a,tuba[i].b,tuba[i].c);
    }
    fclose(fp);
}
//fseek(fp,0,SEEK_END);
/*
fseek(fp,0,SEEK_CUR);
fseek(fp,0,SEEK_SET);
*/ 