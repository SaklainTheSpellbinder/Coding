#include <stdio.h>
#include<string.h>

int main() {
    char tuba[50];
    printf("Who is Tuba? Enter: gadha, pagol, chagol, or moda: ");
    scanf("%s", tuba);

    if (strcmp(tuba, "gadha") == 0)
        printf("Tuba is a gadha!\n");
    else if (strcmp(tuba, "pagol") == 0)
        printf("Tuba is a pagol!\n");
    else if (strcmp(tuba, "chagol") == 0)
        printf("Tuba is a chagol!\n");
    else if (strcmp(tuba, "moda") == 0)
        printf("Tuba is moda, but still lovable.\n");
    else
        printf("Tuba defies all labels and is just Tuba.\n");

    return 0;
}
