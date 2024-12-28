#include<stdio.h>
#include<stdlib.h>
int main(){
    // printf("%d\n",atoi("123"));
    // printf("%d\n",atoi("45abc"));
    // printf("%d\n",atoi("     -789"));
    // printf("%d\n",atoi("Hello"));

    char str[] = "k123abc";
    char *endptr;

    long num = strtol(str, &endptr, 10);  // Convert with base 10
    if (*endptr != '\0')
     {
        printf("Conversion stopped at non-numeric character: %s\n", endptr);
    }

    printf("Converted number: %ld\n", num); // Output: 123

    return 0;
}