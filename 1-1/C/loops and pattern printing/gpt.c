#include <stdio.h>

int is_prime(int number) {
    if (number <= 1) {
        return 0; // False
    }
    else if (number <= 3) {
        return 1; // True
    }
    else if (number % 2 == 0 || number % 3 == 0) {
        return 0; // False
    }
    int i = 5;
    while (i * i <= number) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return 0; // False
        }
        i += 6;
    }
    return 1; // True
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (is_prime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }
    return 0;
}

