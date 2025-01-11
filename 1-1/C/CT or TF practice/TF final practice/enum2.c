// #include <stdio.h>
// enum State {WORKING = 0, FAILED, FREEZED};
// enum State currState = 2;

// enum State FindState() {
//     return currState;
// }

// int main() {
//    (FindState() == WORKING)? printf("WORKING"): printf("NOT WORKING");
//    return 0;
// }

#include <stdio.h>
enum day {sunday = 1, tuesday, wednesday, thursday, friday, saturday,};

int main()
{
    enum day d = thursday;
    printf("The day number stored in d is %d", d);
    return 0;
}