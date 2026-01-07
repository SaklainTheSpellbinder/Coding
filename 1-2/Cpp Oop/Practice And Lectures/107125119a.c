#include <stdio.h>

void check_speed(int speed) {
    if (speed < 60) {
        printf("Safe\n");
    } else if (speed == 60) {
        printf("Warning\n");
    } else {
        printf("Over Speeding!\n");
    }
}

int main() {
    int speed;
    printf("Enter the car's speed (km/h): ");
    scanf("%d", &speed);
    check_speed(speed);
    return 0;
}
