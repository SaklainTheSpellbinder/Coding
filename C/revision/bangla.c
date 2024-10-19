#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    // Set the locale to UTF-8
    setlocale(LC_ALL, "");

    // Define a wide character string containing Bangla text
    wchar_t bangla_text[] = L"বাংলা ভাষা";

    // Print the Bangla text
    wprintf(L"%ls\n", bangla_text);

    return 0;
}
