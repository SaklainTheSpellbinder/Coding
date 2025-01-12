#include<stdio.h>
// 
int main(int argc, char **argv){
    int total = 0, temp;
    printf("Param count: %d\n", argc);
    
    for(int i=1; i<argc;i++){
        sscanf(argv[i], "%d", &temp);
        total += temp;
    }

    printf("%d", total);
    return 0;
}