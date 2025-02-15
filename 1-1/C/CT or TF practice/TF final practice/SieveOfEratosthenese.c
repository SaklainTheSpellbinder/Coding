// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// void sieveOptimized(int N) {
//     if (N < 2) {
//         printf("No prime numbers.\n");
//         return;
//     }

//     // Allocate memory for odd numbers only (skip evens)
//     bool *isPrime = (bool *)malloc(((N / 2) + 1) * sizeof(bool));

//     for (int i = 0; i <= N / 2; i++) isPrime[i] = true;  // Assume all odd numbers are prime

//     printf("Prime numbers up to %d:\n", N);
//     printf("2 ");  // Handle '2' separately since it's the only even prime

//     for (int i = 1; (2 * i + 1) * (2 * i + 1) <= N; i++) {  // Start from 3 (i=1)
//         if (isPrime[i]) {  // If 2*i + 1 is still prime
//             int p = 2 * i + 1;  // Actual prime number

//             for (int j = (p * p) / 2; j <= N / 2; j += p) {  // Mark multiples as non-prime
//                 isPrime[j] = false;
//             }
//         }
//     }

//     // Print primes (odd numbers)
//     for (int i = 1; 2 * i + 1 <= N; i++) {
//         if (isPrime[i]) printf("%d ", 2 * i + 1);
//     }

//     printf("\n");
//     free(isPrime);
// }

// int main() {
//     int N;
//     printf("Enter N: ");
//     scanf("%d", &N);

//     sieveOptimized(N);
//     return 0;
// }
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void sieveOfEratosthenes(int N) {
    bool *isPrime = (bool *)malloc((N + 1) * sizeof(bool));
    for (int i = 0; i <= N; i++) isPrime[i] = true;

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= N; i++)
        if (isPrime[i]) printf("%d ", i);

    free(isPrime);
}

int main() {
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    sieveOfEratosthenes(N);
    return 0;
}
