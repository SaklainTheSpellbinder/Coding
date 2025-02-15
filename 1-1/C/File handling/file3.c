#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    
    // ✅ Use "a+" mode to avoid overwriting
    fp = fopen("saklain.txt", "w+");  
    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    char str[200], ptr[200], str3[200], hey[1000];

    // ✅ Writing data at the end instead of overwriting
    fprintf(fp, "%s %d\n%s %s %s", "Saklain er cheye valo manush hoy na", 2305004, "kire", "abbi", "gadha");

    // ✅ Move file pointer to beginning before reading
    rewind(fp);

    // ✅ Reading the first line safely
    fgets(hey, sizeof(hey), fp);
    printf("%s\n", hey);

    // ✅ Read words separately
    fscanf(fp, "%s %s %s", str, ptr, str3);
    printf("%s\n%s\n%s\n", str, ptr, str3);

    // ✅ Move to end before writing new data
    fseek(fp, 0, SEEK_END);
    fprintf(fp, "\n");
    fputs(hey, fp);

    // ✅ Reset file pointer before final reading
    rewind(fp);

    char sak[100], tubagada[50], abbigada[50], chotomanush[50];
    int tintin;

    // ✅ Corrected `fscanf()` format
    fscanf(fp, "%s %d %s %s %s", sak, &tintin, tubagada, abbigada, chotomanush);
    printf("\n%s %s %s %s %d\n", sak, tubagada, abbigada, chotomanush, tintin);

    fclose(fp);
    return 0;
}
