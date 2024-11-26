#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int* takearray(int n){
    int* t=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    return t;
}

int main(){
    int *v1,*v2;
    v1=takearray(3);
    v2=takearray(3);
    float Crossi,Crossj,Crossk,dot,angle,A,B;
    A=sqrt((*v1)*(*v1)+(*(v1+1)**(v1+1))+(*(v1+2)**(v1+2)));
    B=sqrt((*v2)*(*v2)+(*(v2+1)**(v2+1))+(*(v2+2)**(v2+2)));
    dot=((*v1)*(*v2)+(*(v1+1)**(v2+1))+(*(v1+2)**(v2+2)));
    Crossi=(*(v1+1)**(v2+2))-(*(v1+2)**(v2+1));
    Crossj=(*(v1+2)**(v2))-(*(v1)**(v2+2));
    Crossk=(*(v1)**(v2+1))-(*(v1+1)**(v2));
    angle=acos(dot/(A*B));
    printf("The dot product is: %.3f\n",dot);
    printf("The cross product is: %.2fi+%.2fj+%.2fk\n",Crossi,Crossj,Crossk);
    printf("The angle is %.3f\n",angle);
    free(v1);
    free(v2);
    return 0;
}