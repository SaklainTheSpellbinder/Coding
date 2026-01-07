#include <stdio.h>

int main() {
    int work_hours, exercise_hours, fun_hours;
    int total_score = 0;
    int any_rule_met = 0; 

    printf("Enter hours allocated to Work: ");
    scanf("%d", &work_hours);

    printf("Enter hours allocated to Exercise: ");
    scanf("%d", &exercise_hours);

    printf("Enter hours allocated to Fun: ");
    scanf("%d", &fun_hours);

    if (work_hours >= 6 && work_hours <= 8 && exercise_hours >= 2 && fun_hours >= 1) {
        total_score += 20;
        any_rule_met = 1;
    }

    if (work_hours > 10 && exercise_hours < 2) {
        total_score -= 5;
        any_rule_met = 1;
    }

    if (exercise_hours >= 2 && fun_hours < 1) {
        total_score += 10;
        total_score -= 2; 
        any_rule_met = 1;
    }

    if (any_rule_met == 0) {
        total_score += 5;
    }

    printf("Total score: %d\n", total_score);

    return 0;
}
