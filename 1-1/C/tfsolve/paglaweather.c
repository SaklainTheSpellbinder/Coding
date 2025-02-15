#include<stdio.h>
//should watch weathering with you instead of this
struct District{
    float Temperature;
    float Humidity;
    float Rain;
};
int main(){
    struct District districts[65]={0};
    FILE* fp=fopen("data.txt","r");
    int n;
    float temp;
    float hum;
    float rain;
    while(fscanf(fp,"%d %*d %f %f %f\n",&n,&temp,&hum,&rain)!=EOF){
        districts[n].Temperature+=temp;
        districts[n].Humidity+=hum;
        districts[n].Rain+=rain;
    }
    fclose(fp);
    FILE* ft=fopen("temperature.txt","w");
    FILE* fh=fopen("humidity.txt","w");
    FILE* fr=fopen("rain.txt","w");
    for(int i=1;i<=64;i++){
        fprintf(ft,"%d %f\n",i,(districts[i].Temperature/365.0));
        fprintf(fh,"%d %f\n",i,(districts[i].Humidity/365.0));
        fprintf(fr,"%d %f\n",i,(districts[i].Rain/365.0));
    }
    fclose(ft);
    fclose(fh);
    fclose(fr);
}