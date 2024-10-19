#include<stdio.h>
int main()
{
    int saklain[10] = {1,6,4,3,3,4,5,66,6,57};
    
    for(int i=0;i<=9;i++)
    printf("%p\n",&saklain[i]);
    return 0;

}