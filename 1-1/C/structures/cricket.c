#include<stdio.h>
#include<string.h>
int main(){
    typedef struct cricketer{
        char name[50];
        int age;
        int NumberOfMatches;
        float average;
    }cricketer;
    //3 cricketer
    cricketer arr[3];
    for(int i=0;i<3;i++)
    {
        scanf("%[^\n]",&arr[i].name);
        scanf("%d",&arr[i].age);
        scanf("%d",&arr[i].NumberOfMatches);
        scanf("%f",&arr[i].average);
        getchar();
    }
    
    for(int i=0;i<3;i++)
    {
        printf("%s\n",arr[i].name);
        printf("AGE: %d\n",arr[i].age);
        printf("NUMBER OF MATCHES: %d\n",arr[i].NumberOfMatches);
        printf("AVERAGE: %f\n\n",arr[i].average);
    }
    return 0;
}