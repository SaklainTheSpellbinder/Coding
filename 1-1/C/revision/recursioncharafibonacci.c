#include<stdio.h>
int main(){
    int n;
    printf("To which term:");
    scanf("%d",&n);
    int a=0,b=1,f=a+b;;
    if(n>=2)
        printf("%d\n%d\n",a,b);
    else
        printf("%d",a);
    for(int i=1;i<=(n-2);i++)
    {
        printf("%d\n",f);
        a=b;
        b=f;
        f=a+b;
    }
    return 0;
}