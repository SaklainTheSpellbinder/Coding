#include<stdio.h>
#include<string.h>
char arr[50]="Func_ptrs are crimes against humanity";
char arr3[50]="No, exams are crimes against humanity";
char (*test(int *a[]))[]
{
    return &arr;
}
char (*test2(int *a[]))[]
{
    return &arr3;
}

int main()
{
    char (*(*func[])(int*a[]))[]={test,test2};
    char (*(*func2[]) (int*a[]))[]={test2,test};

    int p,q,r;
    int *b[10];
    b[0]=&p;
    b[1]=&q;
    b[2]=&r;

    char (*cry)[50];
    cry=test(b);
    
    puts(*cry);

    char (*aaaaa)[50];
    aaaaa=func[1](b);
    puts(*aaaaa);
    
    return 0;
}