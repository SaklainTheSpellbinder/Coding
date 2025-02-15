#include<stdio.h>

double sinX(double x,int n){
    double t=x;
    double result=0;
    int i=1;
    while(i<n){
        result+=t;
        t*=-x*x/((2*i+1)*(2*i));
        i++;
    }
    return result;
}

double cosX(double x,int n){
    double t=1;
    double result=0;
    int i=1;
    while(i<n){
        result+=t;
        t*=-x*x/((2*i-1)*(2*i));
        i++;
    }
    return result;
}

double Harmonic(double x,int n){
    double t=1;
    double result=0;
    int i=1;
    while(i<n){
        result+=t;
        t*=1/i;
        i++;
    }
    return result;
}

int main(){
    double x;
    int n;
    scanf("%lf%d",&x,&n);
    printf("%lf",cosX(x,n));
}