char shiftLetter(char start, int shift) {
    // Ensure the input is a valid letter
    if ((start >= 'A' && start <= 'Z') || (start >= 'a' && start <= 'z')) {
        int isUpperCase = (start >= 'A' && start <= 'Z');
        int base = isUpperCase ? 'A' : 'a';

        // Calculate the new position with wrap-around for left shift
        int newPos = ((start - base + shift) % 26 + 26) % 26;

        // Return the shifted letter
        return base + newPos;
    } else {
        // Return the original character if it's not a valid letter
        return start;
    }
}

int main() {
    char start;
    int shift;

    printf("Enter the starting letter: ");
    scanf(" %c", &start);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    char result = shiftLetter(start, shift);
    printf("The shifted letter is: %c\n", result);

    return 0;
}
