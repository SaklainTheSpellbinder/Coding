#include<stdio.h>
#include<stdio.h>
long long decToBin(int num){
    static int i=0;
    printf("decToBin called with num = %d\n", num); // Debug print

    if(num==0){
        printf("Base case: num is 0, returning 0\n"); // Debug print
        return 0;
    }
    if(num==1){
        printf("Base case: num is 1, returning 1\n"); // Debug print
        return 1;
    }

    long long result = 10 * decToBin(num/2) + (num%2);
    printf("For num = %d, returning %lld (calculated from 10 * decToBin(%d) + %d)\n",
           num, result, num/2, num%2); // Debug print
    return result;
}
int main(){
    int n=13;
    int reversebit=0;
    // while(n){
    //     reversebit=reversebit*2+(n%2);
    //     n/=2;
    // }
    
    printf("%d",decToBin(n));
}