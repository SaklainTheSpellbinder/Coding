#include<stdio.h>
#include<string.h>

int string_length(char str[]);
void string_copy(char str[], char ptr[], char ttr[], int n);
int substring_index(char str[], char ptr[], int n);

int main() {
    char s1[100];
    char s2[100];
    char s3[100];
    
    printf("s1 = ");
    fgets(s1, 98, stdin);
    s1[strcspn(s1, "\n")] = '\0'; // Remove newline from fgets input.

    printf("s2 = ");
    scanf("%s", s2);

    printf("s3 = ");
    scanf("%s", s3);

    int i = 0;
    int lenstr = string_length(s1);
    int lensub = string_length(s2);

    while (i <= lenstr - lensub) {
        int idx = substring_index(s1, s2, i);
        if (idx == -1) break; // Exit if no more substrings are found.
        string_copy(s1, s2, s3, idx);
        i = idx + string_length(s3);
    }

    printf("Result: %s\n", s1);
    return 0;
}

int substring_index(char str[], char ptr[], int n) {
    int lenstr = string_length(str);
    int lensub = string_length(ptr);
    for (int i = n; i <= lenstr - lensub; i++) {
        int j = 0;
        while (j < lensub && str[i + j] == ptr[j]) {
            j++;
        }
        if (j == lensub) {
            return i; // Found substring.
        }
    }
    return -1; // Substring not found.
}

void string_copy(char str[], char ptr[], char ttr[], int n) {
    int lensub = string_length(ptr);
    int lenrep = string_length(ttr);
    int lenstr = string_length(str);

    // Shift characters if replacement is shorter or longer.
    if (lenrep != lensub) {
        for (int i = lenstr; i >= n + lensub; i--) {
            str[i + lenrep - lensub] = str[i];
        }
    }

    // Replace the substring with the new one.
    for (int i = 0; i < lenrep; i++) {
        str[n + i] = ttr[i];
    }

    // Update null-terminator.
    str[lenstr + lenrep - lensub] = '\0';
}

int string_length(char str[]) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}
