#include <stdio.h>

#define DAYS 7
#define HOURS 7

const char* schedule[DAYS][HOURS] = {
    {"8:00 - 9:00", "9:00 - 10:00", "10:00 - 11:00", "11:00 - 12:00", "12:00 - 1:00", "1:00 - 2:00", "2:00 - 3:00"},
    {"CT", "PHY 114 Lab এর পড়া revise", "MATH 141", "PHY 114", "", "LUNCH BREAK", ""},
    {"Codeforces", "CSE 101", "EEE 163", "MATH 141", "CSE 103", "LUNCH BREAK", ""},
    {"CT", "MATH 141", "EEE 163", "PHY 129", "CSE 103", "LUNCH BREAK", "EEE 163 এর পড়া"},
    {"Codeforces", "CSE 101", "EEE 163", "EEE 164 (EEE) CL1", "", "MATH 141 এর পড়া", "CSE 102 PL এর পড়া"},
    {"CT", "PHY 129", "CSE 101", "PHY 129", "CSE 103", "LUNCH BREAK", "PHY 129 এর পড়া"},
    {"Codeforces", "EEE 163 এর পড়া", "PHY 129 এর পড়া", "PHY 129", "MATH 141 এর পড়া", "LUNCH BREAK", "CSE 101 এর পড়া"}
};

void printSchedule() {
    const char* days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    
    for (int i = 0; i < DAYS; i++) {
        printf("%s:\n", days[i]);
        for (int j = 0; j < HOURS; j++) {
            if (schedule[i][j][0] != '\0') {
                printf("%s\n", schedule[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    printSchedule();
    return 0;
}
