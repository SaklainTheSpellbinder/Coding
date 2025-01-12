#include<stdio.h>

#define PI 3.1416
#define SIZE 5
#define min3(a, b, c) min(min((a), (b)), (c))


#define min(a, b) ((a)>(b)?(b):(a))
#define abs(a) ((a)>0?(a):-(a))
#define swap(a,b) t=a;a=b;b=t;


#define print(a,b) printf("Value of A and B: %d, %d\n", a, b);

int main(){
    int arr[SIZE];
    printf("Value of PI: %lf\n", PI);;
    printf("Value of PI: %lf\n", 3.1416);

    printf("Min: %lf\n", min(54.45, 758.45));
    printf("Min: %d\n", min(2, 3)+10);
    printf("Min3: %d\n", min3(2, 3, 10));
    printf("Abs: %d\n", abs(-5-2));

    int a = 50, b=60, t;

    print(a, b);
    swap(a,b);
    print(a, b);

    return 0;
}