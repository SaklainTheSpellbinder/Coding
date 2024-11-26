#include <stdio.h>
#include <locale.h>

int main() {
    // Set the locale to support UTF-8
    setlocale(LC_ALL, "");

    int x;
    printf("Enter your number: ");
    scanf("%d", &x);

    if (x >= 80)
        printf("অনন্য\n");
    else if (x >= 70)
        printf("অর্জনমুখী\n");
    else if (x >= 60)
        printf("অগ্রগামী\n");
    else if (x >= 50)
        printf("সক্রিয়\n");
    else if (x >= 40)
        printf("অনুসন্ধানী\n");
    else if (x >= 33)
        printf("বিকাশমান\n");
    else
        printf("প্রারম্ভিক\n");

    return 0;
}
