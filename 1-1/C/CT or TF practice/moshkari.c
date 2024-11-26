#include<stdio.h>
#include<math.h>
int main(){
    float a,b,c;
    scanf("%f%f%f",&a,&b,&c);
    if(((a+b)>c) && ((b+c)>a) && ((c+a)>b))
        {
            float s=(a+b+c)/2;
            float area=sqrt(s*(s-a)*(s-b)*(s-c));
            printf("%.1f",area);
        }
    else
        printf("No triangle possible");
    return 0;
}