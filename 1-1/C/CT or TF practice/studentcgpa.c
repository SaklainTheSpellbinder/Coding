#include<stdio.h>
struct student{
    long long int ID;
    char name[1000];
    float cg;
};
int main(){
    int n;
    scanf("%d",&n);
    struct student stu[n];
    for(int i=0;i<n;i++){
        printf("\nID: ");
        scanf("%lld",&stu[i].ID);
        printf("Name: ");
        scanf("%s",stu[i].name);
        printf("CGPA: ");
        scanf("%f",&stu[i].cg);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(stu[j].cg<stu[i].cg){
                min=j;
            }
        }
        if(min!=1){
            struct student temp=stu[min];
            stu[min]=stu[i];
            stu[i]=temp;
        }
    }
    for(int i=0;i<n;i++){
        printf("%lld %s %f\n",stu[i].ID,stu[i].name,stu[i].cg);
    }
}